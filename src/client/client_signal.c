/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:39:23 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/25 19:45:44 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_connection(int income, int check);

static void	cl_handler_act(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_putstr_fd("Client signal handler SIGUSR>>1 msg..\n", STDOUT_FILENO);
		ft_connection(SIG_SET, SIG_SET);
	}
	if (signal == SIGUSR2)
	{
		ft_putstr_fd("Client signal handler SIGUSR>>2 msg..\n", STDOUT_FILENO);
	}
}

static int	ft_connection(int income, int check)
{
	static volatile int	connection;

	if (check == SIG_SET)
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
		// write(STDOUT_FILENO, &body_msg[index], 1);
		send_bit(input_pid, body_msg[index]);
		index++;
	}
	free(body_msg);
}

void	send_bit(int input_pid, char c)
{
	int	bit_index;

	bit_index = BYTE_SIZE;
	while (bit_index >= SIG_DEFAULT)
	{
		ft_connection(SIG_DEFAULT, SIG_SET);
		if (((c >> bit_index) & BIT) == SIG_PENDING_NO)
		{
			if (kill(input_pid, SIGUSR1))
				ft_error_msg("SIGUSR1 - Server offline or invalid PID.\n");
		}	
		else if (((c >> bit_index) & BIT) == SIG_PENDING_YES)
			if (kill(input_pid, SIGUSR2))
				ft_error_msg("SIGUSR2 - Server offline or invalid PID.\n");
		while (!ft_connection(SIG_DEFAULT, SIG_GET))
			;
		bit_index--;
	}
}

void	cl_sendingsignal(int input_pid, char *msg)
{
	struct sigaction	client_act;

	sigemptyset(&client_act.sa_mask);
	// ft_memset(&client_act, SIG_DEFAULT, sizeof(client_act));
	client_act.sa_flags = SA_SIGINFO;
	// client_act.sa_flags = SIG_DEFAULT;
	client_act.sa_handler = cl_handler_act;
	if ((sigaction(SIGUSR1, &client_act, NULL) == CLIENT_FAIL)
		|| (sigaction(SIGUSR2, &client_act, NULL) == CLIENT_FAIL))
		ft_error_msg("Client signal failed.\n");
	cl_handle_msg(input_pid, msg);
}
