#include "minitalk.h"

void	handle_sigusr1(int sig)
{
	(void)sig;
	printf("Clementine\n");
}

int	main(int argc, char **argv)
{
	int	my_pid;
	struct sigaction sa = {0};

	(void)argc;
	(void)argv;
	my_pid = getpid();
	printf("PID = %d\n", my_pid);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = &handle_sigusr1;
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
	{
		printf("Wait for msg\n");
		sleep(5);
	}
	return (0);
}
