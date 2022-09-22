#include "minitalk.h"

void	handle_sigusr1(int sig)
{
	(void)sig;
	printf("Clementine\n");
}

int	main(int argc, char **argv)
{
	int	my_pid;

	(void)argc;
	(void)argv;
	my_pid = getpid();
	printf("PID = %d\n", my_pid);

	struct sigaction sa = {0};
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = &handle_sigusr1;
	sigaction(SIGUSR1, &sa, NULL);

	while (1)
	{
		printf("Wait for msg\n");
		sleep(5);
	}

	int	x;
	printf("What is the result of 3 x 5\n");
	scanf("%d", &x);
	if (x == 15)
		printf("Right!\n");
	else
		printf("Wrong!\n");
	return (0);
}