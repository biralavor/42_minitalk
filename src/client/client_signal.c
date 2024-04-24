/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:39:23 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/24 12:31:00 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_connection(int income, int check);

static void	cl_handler_act(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_putstr_fd("Client signal handler SIGUSR>>1 msg..\n", STDOUT_FILENO);
		ft_connection(SET, SET);
	}
	if (signal == SIGUSR2)
	{
		ft_putstr_fd("Client signal handler SIGUSR>>2 msg..\n", STDOUT_FILENO);
	}
}

static int	ft_connection(int income, int check)
{
	static volatile int	connection;

	if (check == SET)
		connection = income;
	return (connection);
}

void	cl_handle_msg(int input_pid, char *msg)
{
	int		index;
	char	*body_msg;

	index = 0;
	body_msg = ft_strdup(msg);
	(void)input_pid;
	while (body_msg[index] != '\0')
	{
		write(STDOUT_FILENO, &body_msg[index], 1);
		index++;
	}
	free(body_msg);
}

void	cl_sendingsignal(int input_pid, char *msg)
{
	struct sigaction	client_act;

	sigemptyset(&client_act.sa_mask);
	// ft_memset(&client_act, CL_DEFAULT, sizeof(client_act));
	client_act.sa_flags = SA_SIGINFO;
	// client_act.sa_flags = CL_DEFAULT;
	client_act.sa_handler = cl_handler_act;
	if ((sigaction(SIGUSR1, &client_act, NULL) == CLIENT_FAIL)
		|| (sigaction(SIGUSR2, &client_act, NULL) == CLIENT_FAIL))
		ft_error_msg("Client signal failed.\n");
	cl_handle_msg(input_pid, msg);
}
