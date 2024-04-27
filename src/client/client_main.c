/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:06:25 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/27 14:57:15 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	cl_init(int server_pid)
{
	ft_putstr_fd(YELLOW, STDOUT_FILENO);
	ft_putstr_fd("Client is starting...\n", STDOUT_FILENO);
	ft_putstr_fd("Now, trying to connect with Server's PID: ", STDOUT_FILENO);
	ft_putstr_fd(CYAN, STDOUT_FILENO);
	ft_putnbr_fd(server_pid, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	ft_putstr_fd(YELLOW, STDOUT_FILENO);
	ft_putstr_fd("Client is running...\n", STDOUT_FILENO);
}

int	main(int argc, char **argv)
{
	int					server_pid;
	int					next_char;

	next_char = 0;
	server_pid = arg_validation(argc, argv[ARG_PID]);
	cl_init(server_pid);
	if (cl_sigaction_init())
	{
		while (argv[ARG_MSG][next_char] != '\0')
		{
			ft_putstr_fd("\nSending the char >> ", STDOUT_FILENO);
			ft_putchar_fd(argv[ARG_MSG][next_char], STDOUT_FILENO);
			ft_putstr_fd(" >> ", STDOUT_FILENO);
			cl_send_bit(server_pid, argv[ARG_MSG][next_char]);
			next_char++;
		}
		exit(EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
