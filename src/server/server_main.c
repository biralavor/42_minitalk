/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:06:25 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/20 17:38:51 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_msg_error(char *str);

static void	handler_act(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	(void)info;
	if (sig == SIGUSR1)
	{
		ft_putstr_fd("User 1\n", STDOUT_FILENO);
	}
	
}

int	main(void)
{
	struct sigaction	server_act;

	sigemptyset(&server_act.sa_mask);
	server_act.sa_flags = SA_SIGINFO;
	server_act.sa_sigaction = handler_act;
	if ((sigaction(SIGUSR1, &server_act, NULL) == SERVER_FAIL)
		|| (sigaction(SIGUSR2, &server_act, NULL) == SERVER_FAIL))
		ft_msg_error("Error >> Server signal failed.\n");
	ft_putstr_fd("Server is Starting...\n", STDOUT_FILENO);
	ft_putstr_fd("Server PID: ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putstr_fd("\n\n", STDOUT_FILENO);
	while (WAIT)
	{
		ft_putstr_fd("Server is Running...\n", STDOUT_FILENO);
		sleep(2);
	}
	exit(EXIT_SUCCESS);
}

static void	ft_msg_error(char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
