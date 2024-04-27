/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:06:25 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/27 16:27:57 by umeneses         ###   ########.fr       */
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

void	cl_msg_header(int server_pid)
{
	int		index;
	char	*color;
	char	*header;
	char	*msg_header;

	index = 0;
	color = CYAN;
	header = "\n########### Client's Message ###########";
	msg_header = ft_strjoin(color, header);
	while (msg_header[index] != '\0')
	{
		cl_send_bit(server_pid, msg_header[index]);
		index++;
	}
	free(msg_header);
	cl_send_bit(server_pid, '\n');
}

void	cl_msg_tail(int server_pid)
{
	int		index;
	char	*color;
	char	*tail;
	char	*msg_tail;

	index = 0;
	color = CYAN;
	tail = "\n########################################";
	msg_tail = ft_strjoin(color, tail);
	while (msg_tail[index] != '\0')
	{
		cl_send_bit(server_pid, msg_tail[index]);
		index++;
	}
	free(msg_tail);
	cl_send_bit(server_pid, '\n');
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
		cl_msg_header(server_pid);
		while (argv[ARG_MSG][next_char] != '\0')
		{
			cl_send_bit(server_pid, argv[ARG_MSG][next_char]);
			next_char++;
		}
		cl_msg_tail(server_pid);
		exit(EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
