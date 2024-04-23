/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:06:25 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/23 14:24:51 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	server_pid;

	server_pid = arg_validation(argc, argv[PID]);
	ft_putstr_fd(YELLOW, STDOUT_FILENO);
	ft_putstr_fd("Client is Starting...\n", STDOUT_FILENO);
	ft_putstr_fd("Now, connecting to Server using PID: ", STDOUT_FILENO);
	ft_putstr_fd(CYAN, STDOUT_FILENO);
	ft_putnbr_fd(server_pid, STDOUT_FILENO);
	if (kill(server_pid, SIGUSR1) == CLIENT_FAIL)
		ft_error_msg("Client failed to send signal to Server.\n");
	ft_putstr_fd("\n", STDOUT_FILENO);
	ft_putstr_fd(YELLOW, STDOUT_FILENO);
	// client_signal(server_pid, argv[MSG_ARG]);
	ft_putstr_fd("Client is running...\n", STDOUT_FILENO);
	while (1)
		sleep(5);
	exit(EXIT_SUCCESS);
}
