/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:39:23 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/27 13:31:10 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_connection(int income, int check);

static void	server_signal_handler(int signal)
{
	if (signal == SIGUSR1)
		ft_connection(SIG_SET, SIG_SET);
}

// void	cl_send_msg(int server_pid, const char *msg)
// {
// 	int		index;
// 	char	*body_msg;

// 	index = 0;
// 	body_msg = ft_strdup(msg);
// 	(void)server_pid;
// 	while (body_msg[index] != '\0')
// 	{
// 		// write(STDOUT_FILENO, &body_msg[index], 1);
// 		cl_send_bit(server_pid, body_msg[index]);
// 		index++;
// 	}
// 	free(body_msg);
// 	cl_send_bit(server_pid, '\n');
// }

void	cl_send_bit(int server_pid, char c_msg)
{
	int	bit_index;
	int	bit_signal;

	bit_index = BYTE_SIZE;
	while (--bit_index >= SIG_DEFAULT)
	{
		ft_connection(SIG_DEFAULT, SIG_SET);
		bit_signal = (c_msg >> bit_index) & BIT;
		if (bit_signal == SIG_PENDING_NO)
		{
			if (kill(server_pid, SIGUSR1) == CLIENT_FAIL)
				ft_error_msg("SIGUSR1 - Server offline or invalid PID.\n");
		}	
		else if (bit_signal == SIG_PENDING_YES)
			if (kill(server_pid, SIGUSR2) == CLIENT_FAIL)
				ft_error_msg("SIGUSR2 - Server offline or invalid PID.\n");
		while (!ft_connection(SIG_DEFAULT, SIG_GET))
			;
	}
}

static int	ft_connection(int income, int check)
{
	static volatile int	connection;

	if (check == SIG_SET)
		connection = income;
	return (connection);
}

// void	cl_sendingsignal(int server_pid, char c_msg)
// {
// 	struct sigaction	client_act;

// 	// sigemptyset(&client_act.sa_mask);
// 	// client_act.sa_flags = SA_SIGINFO;
// 	ft_memset(&client_act, SIG_DEFAULT, sizeof(client_act));
// 	client_act.sa_handler = server_signal_handler;
// 	client_act.sa_flags = SIG_DEFAULT;
// 	if ((sigaction(SIGUSR1, &client_act, NULL) == CLIENT_FAIL))
// 		ft_error_msg("Client signal failed.\n");
// 	cl_send_bit(server_pid, c_msg);
// }
