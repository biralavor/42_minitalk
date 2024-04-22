/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:06:25 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/22 17:22:54 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	server_pid;

	server_pid = arg_validation(argc, argv[PID]);
	ft_putstr_fd("Client is Starting...\n", STDOUT_FILENO);
	ft_putstr_fd("Now, connecting to Server using PID: ", STDOUT_FILENO);
	ft_putnbr_fd(server_pid, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	while (1)
	{
		ft_putstr_fd("Client is running...\n", STDOUT_FILENO);
		sleep(3);
	}
	exit(EXIT_SUCCESS);
}
