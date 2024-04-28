/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_val_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:44:06 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/28 14:30:32 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

pid_t	arg_validation(int argc, char *pid_input)
{
	pid_t	server_pid;

	if (argc != ARG_SIZE)
	{
		ft_putstr_fd(RED, STDOUT_FILENO);
		ft_putstr_fd("Please, hit on client's terminal:\n", STDOUT_FILENO);
		ft_putstr_fd(YELLOW, STDOUT_FILENO);
		ft_putstr_fd("\n./client server_PID YOUR_MESSAGE\n", STDOUT_FILENO);
		ft_error_msg("Invalid number of arguments.\n");
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(pid_input);
	while (*pid_input)
	{
		if (!ft_isdigit(*pid_input++))
		{
			ft_putstr_fd(RED, STDOUT_FILENO);
			ft_putstr_fd("PID has be a number. ", STDOUT_FILENO);
			ft_error_msg("Check it on Server's terminal.\n");
		}
	}
	return (server_pid);
}
