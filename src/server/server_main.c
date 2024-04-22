/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:06:25 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/22 18:06:40 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sv_handler_act(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	(void)info;
	if (sig == SIGUSR1)
	{
		ft_putstr_fd("inside server SIGUSR >> 1\n", STDOUT_FILENO);
	}
	if (sig == SIGUSR2)
	{
		ft_putstr_fd("inside server SIGUSR >> 2\n", STDOUT_FILENO);
	}
}

int	main(void)
{
	struct sigaction	server_act;

	// sigemptyset(&server_act.sa_mask);
	ft_memset(&server_act, SV_DEFAULT, sizeof(server_act));
	server_act.sa_flags = SA_SIGINFO;
	server_act.sa_sigaction = sv_handler_act;
	if ((sigaction(SIGUSR1, &server_act, NULL) == SERVER_FAIL)
		|| (sigaction(SIGUSR2, &server_act, NULL) == SERVER_FAIL))
		ft_error_msg("Server signal failed.\n");
	ft_putstr_fd("Server is Starting...\n", STDOUT_FILENO);
	ft_putstr_fd("Server PID: ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putstr_fd("\n\n", STDOUT_FILENO);
	while (WAIT)
	{
		ft_putstr_fd("Server is Running...\n", STDOUT_FILENO);
		sleep(3);
	}
	exit(EXIT_SUCCESS);
}
