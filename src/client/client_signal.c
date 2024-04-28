/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:39:23 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/28 13:34:04 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	server_signal_handler(int signal);
static int	ft_connection(int income, int check);

bool	cl_sigaction_init(void)
{
	struct sigaction	client_act;

	if (ft_memset(&client_act, SIG_DEFAULT, sizeof(client_act)))
	{	
		client_act.sa_handler = server_signal_handler;
		client_act.sa_flags = SIG_DEFAULT;
		sigaction(SIGUSR1, &client_act, NULL);
		return (true);
	}
	ft_error_msg("Client signal initialization failed.\n");
	return (false);
}

static void	server_signal_handler(int signal)
{
	if (signal == SIGUSR1)
		ft_connection(SIG_SET, SIG_SET);
}

static int	ft_connection(int income, int check)
{
	static volatile int	connection;

	if (check == SIG_SET)
		connection = income;
	return (connection);
}

void	cl_send_bit(int server_pid, char c_msg)
{
	int		bit_index;
	char	bit_signal;

	bit_index = 0;
	while (bit_index < BYTE_SIZE)
	{
		ft_connection(SIG_DEFAULT, SIG_SET);
		bit_signal = (c_msg >> bit_index & BIT);
		if (bit_signal == SIG_PENDING_NO)
		{
			if (kill(server_pid, SIGUSR1) == CLIENT_FAIL)
				ft_error_msg("Server is offline. Run './server' again\n");
		}	
		else if (bit_signal == SIG_PENDING_YES)
		{
			if (kill(server_pid, SIGUSR2) == CLIENT_FAIL)
				ft_error_msg("Server is offline. Run './server' again\n");
		}
		bit_index++;
		while (!ft_connection(SIG_DEFAULT, SIG_GET))
			;
	}
}
