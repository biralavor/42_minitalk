/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:06:25 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/20 12:31:02 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	handler_sigusr1(int sig)
{
	(void)sig;
	printf("User 1\n");
}

int	main(void)
{
	struct sigaction	sigact;


		while (1)
		{
			sigemptyset(&sigact.sa_mask);
			sigact.sa_handler = &handler_sigusr1;
			printf("Server is Starting...\n");
			sigaction(SIGUSR1, &sigact, NULL);
			sleep(1);
		}
	return (0);
}
