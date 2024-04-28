/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:33:11 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/28 15:38:30 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	cl_init(int server_pid, char *msg)
{
	ft_putstr_fd(YELLOW, STDOUT_FILENO);
	ft_putstr_fd("Client Bonus is starting...\n", STDOUT_FILENO);
	ft_putstr_fd("Now, trying to connect with Server's PID: ", STDOUT_FILENO);
	ft_putstr_fd(CYAN, STDOUT_FILENO);
	ft_putnbr_fd(server_pid, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	ft_putstr_fd(GREEN, STDOUT_FILENO);
	ft_putstr_fd("Client Bonus sent your message >>> ", STDOUT_FILENO);
	ft_putstr_fd(YELLOW, STDOUT_FILENO);
	ft_putstr_fd(msg, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
}

int	main(int argc, char **argv)
{
	int	server_pid;
	int	next_char;

	next_char = 0;
	server_pid = arg_validation(argc, argv[ARG_PID]);
	cl_init(server_pid, argv[ARG_MSG]);
	if (cl_sigaction_init())
	{
		while (argv[ARG_MSG][next_char] != '\0')
		{
			cl_send_bit(server_pid, argv[ARG_MSG][next_char]);
			next_char++;
		}
		exit(EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
