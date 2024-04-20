/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_val.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:44:06 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/20 17:01:21 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_msg_error(char *str);

int	arg_validation(int argc, char *pid_input)
{
	int	server_pid;

	if (argc != ARG_SIZE)
	{
		ft_msg_error("Error >> Invalid number of arguments.\n");
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(pid_input);
	while (*pid_input)
	{
		if (!ft_isdigit(*pid_input++))
			ft_msg_error("Error >> Invalid PID.\n");
	}
	return (server_pid);
}

static void	ft_msg_error(char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
