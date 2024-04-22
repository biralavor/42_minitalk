/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_val.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:44:06 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/22 17:37:26 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	arg_validation(int argc, char *pid_input)
{
	int	server_pid;

	if (argc != ARG_SIZE)
	{
		ft_error_msg("Error >> Invalid number of arguments.\n");
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(pid_input);
	while (*pid_input)
	{
		if (!ft_isdigit(*pid_input++))
		{
			ft_putstr_fd("Error >> PID should be a number. ", STDOUT_FILENO);
			ft_error_msg("Check your Server's terminal.\n");
		}
	}
	return (server_pid);
}
