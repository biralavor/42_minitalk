/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:06:25 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/26 21:24:32 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	server_signal_handler(int signal);
static int	ft_connection(int income, int check);

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
	int	bit_index;
	int	bit_signal;

	bit_index = BYTE_SIZE;
	while (--bit_index >= SIG_DEFAULT)
	{
		ft_connection(SIG_DEFAULT, SIG_SET);
		bit_signal = (c_msg >> bit_index & BIT);
		if (bit_signal == SIG_PENDING_NO)
		{
			if (kill(server_pid, SIGUSR1) == CLIENT_FAIL)
				ft_error_msg("Server is offline. Run './server' again\n");
		}	
		else if (bit_signal == SIG_PENDING_YES)
			if (kill(server_pid, SIGUSR2) == CLIENT_FAIL)
				ft_error_msg("Server is offline. Run './server' again\n");
		while (!ft_connection(SIG_DEFAULT, SIG_GET))
			;
	}
}

void	cl_init(int server_pid)
{
	ft_putstr_fd(YELLOW, STDOUT_FILENO);
	ft_putstr_fd("Client is starting...\n", STDOUT_FILENO);
	ft_putstr_fd("Now, trying to connect with Server's PID: ", STDOUT_FILENO);
	ft_putstr_fd(CYAN, STDOUT_FILENO);
	ft_putnbr_fd(server_pid, STDOUT_FILENO);
	// if (kill(server_pid, SIGUSR1) == CLIENT_FAIL
	// 	|| kill(server_pid, SIGUSR2) == CLIENT_FAIL)
	// 	ft_error_msg("Client failed to send signal to Server.\n");
	ft_putstr_fd("\n", STDOUT_FILENO);
	ft_putstr_fd(YELLOW, STDOUT_FILENO);
	ft_putstr_fd("Client is running...\n", STDOUT_FILENO);
	ft_putstr_fd("Type a new message:\n", STDOUT_FILENO);
	ft_putstr_fd(">> ", STDOUT_FILENO);
}

int	main(int argc, char **argv)
{
	int					server_pid;
	int					next_char;
	struct sigaction	client_act;

	next_char = 0;
	server_pid = arg_validation(argc, argv[ARG_PID]);
	cl_init(server_pid);
	// sigemptyset(&client_act.sa_mask);
	// client_act.sa_flags = SA_SIGINFO;
	ft_memset(&client_act, SIG_DEFAULT, sizeof(client_act));
	client_act.sa_handler = server_signal_handler;
	client_act.sa_flags = SIG_DEFAULT;
	if ((sigaction(SIGUSR1, &client_act, NULL) == CLIENT_FAIL))
		ft_error_msg("Client signal failed.\n");
	while (argv[ARG_MSG][next_char] != '\0')
	{
		cl_send_bit(server_pid, argv[ARG_MSG][next_char]);
		next_char++;
	}
	cl_send_bit(server_pid, '\n');
	exit(EXIT_SUCCESS);
}
