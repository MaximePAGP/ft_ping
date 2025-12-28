
#include "../inc/data.h"
#include <stdio.h> 
#include <signal.h>
#include <stdlib.h>

static	void handle_signals(int signal)
{
	if (signal == SIGINT) {
		G_IS_RUNNING = 0;
	} 
}


void	catch_signals(void)
{
	struct sigaction	sa;

	sa.sa_handler = &handle_signals;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGINT, &sa, NULL) < 0)
	{
		write(STDERR_FILENO, "SIGINT action crashed!", 23);
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGQUIT, &sa, NULL) < 0)
	{
		write(STDERR_FILENO, "SIGQUIT action crashed!", 24);
		exit(EXIT_FAILURE);
	}
}