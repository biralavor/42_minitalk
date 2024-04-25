/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   study_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:54:52 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/25 19:36:05 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/signal.h>    // for signals
#include <stdlib.h>        // for exit
#include <unistd.h>        // for sleep
#include <string.h>        // for memset
#include <stdio.h>         // for printf

void	cleanup (int signum)
{
	printf("Caugth the signal number: %d\n", signum);
	printf("Doing program clean-up and exiting...\n");
	exit(-1);
}

void	handle_sigtstp(int sig)
{
	printf("\nNOT TODAY, haha\n");
}

int	main (int argc, char **argv)
{
	struct sigaction	sigact;		// signal action structure
	char				*client_char;

	client_char = NULL;
	// memset((void *)&sigact, 0, sizeof(sigact));	// zero memory for sigact struct
	sigemptyset(&sigact.sa_mask);			// to initialize and clear all the bits
	// sigact.sa_handler = cleanup;				// set signal handler function
	sigact.sa_handler = &handle_sigtstp;		// another set signal handler function
	sigact.sa_flags = SA_RESTART;
	if (argc == 2)
	{
		client_char = argv[1];
		sigaction(SIGTSTP, &sigact, NULL);
		// SIGTSTP = to avoid terminate with 'Ctrl+Z' signal
		// in this case, the 3rd param will be NULL because I don't have another
		// sigaction to use the actual result in that sigaction
		while (1)
		{
			printf("client char = %s -> pid[%d}\n", client_char, getpid());
			printf("Now, try to stop me with 'Ctrl+Z'\n");
			sleep(1);
		}
		return (0);
	}
	else
	{
		printf("Usage: ./a.out [char]\n");
		return (-1);
	}
	return(0);
}
