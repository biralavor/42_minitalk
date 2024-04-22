/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:39:23 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/22 18:06:56 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	client_signal(int input_pid, char *msg)
{
	struct sigaction	client_act;

	// sigemptyset(&client_act.sa_mask);
	ft_memset(&client_act, CL_DEFAULT, sizeof(client_act));
	// client_act.sa_flags = SA_SIGINFO;
	client_act.sa_flags = CL_DEFAULT;
	client_act.sa_handler = cl_handler_act;
	if ((sigaction(SIGUSR1, &client_act, NULL) == CLIENT_FAIL)
		|| (sigaction(SIGUSR2, &client_act, NULL) == CLIENT_FAIL))
		ft_error_msg("Client signal failed.\n");
	ft_putstr_fd("ADD MY FT_MSG_HANDLER...\n", STDOUT_FILENO);
}

static void	cl_handler_act(int signal)
{
	if (signal == SIGURS1)
	{
		ft_putstr_fd("Now, SIGUSR>>1 msg..\n", STDOUT_FILENO);
		ft_connection(SET, SET);
	}
	if (signal == SIGURS2)
	{
		ft_putstr_fd("Now, SIGUSR>>2 msg..\n", STDOUT_FILENO);
		ft_connection(SET, SET);
	}
}

static int	ft_connection(int income, int check)
{
	static volatile int	connection;

	if (check == SET)
		connection = income;
	return (connection);	
}
