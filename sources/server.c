#include "minitalk.h"

void	handle_sigusr1(int sig)
{
	(void)sig;
	printf("1\n");
}

void	handle_sigusr2(int sig)
{
	(void)sig;
	printf("0\n");
}

int	main(int argc, char **argv)
{
	int	my_pid;
	struct sigaction sa = {0};
	struct sigaction sb = {0};

	(void)argc;
	(void)argv;
	my_pid = getpid();
	printf("PID = %d\n", my_pid);
	sa.sa_handler = &handle_sigusr1;
	sb.sa_handler = &handle_sigusr2;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sb, NULL);
	while (1)
	{
		//printf("Wait for msg\n");
		sleep(5);
	}
	return (0);
}
