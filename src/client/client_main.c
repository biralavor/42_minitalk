/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:06:25 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/24 12:29:31 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	cl_init(int server_pid)
{
	ft_putstr_fd(YELLOW, STDOUT_FILENO);
	ft_putstr_fd("Client is starting...\n", STDOUT_FILENO);
	ft_putstr_fd("Now, connecting to Server using PID: ", STDOUT_FILENO);
	ft_putstr_fd(CYAN, STDOUT_FILENO);
	ft_putnbr_fd(server_pid, STDOUT_FILENO);
	if (kill(server_pid, SIGUSR1) == CLIENT_FAIL
		|| kill(server_pid, SIGUSR2) == CLIENT_FAIL)
		ft_error_msg("Client failed to send signal to Server.\n");
	ft_putstr_fd("\n", STDOUT_FILENO);
	ft_putstr_fd(YELLOW, STDOUT_FILENO);
	ft_putstr_fd("Client is running...\n", STDOUT_FILENO);
}

int	main(int argc, char **argv)
{
	int	server_pid;

	server_pid = arg_validation(argc, argv[PID]);
	cl_init(server_pid);
	while (1)
	{
		// ft_putstr_fd("Type your message:\n", STDOUT_FILENO);
		// ft_putstr_fd(">> ", STDOUT_FILENO);
		// cl_sendingsignal(server_pid, argv[MSG_ARG]);
		sleep(10);
	}
	exit(EXIT_SUCCESS);
}
