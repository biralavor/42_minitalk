/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:49:06 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/23 17:31:48 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libs/libft/includes/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <fcntl.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define COLOR_RESET "\033[0m"

enum e_server
{
	SV_DEFAULT = 0,
	BYTE_SIZE = 8,
	BIT = 1,
	SERVER_FAIL = -1,
	RESET = 0,
	WAIT = 1,
};

enum e_client
{
	CL_DEFAULT = 0,
	CLIENT_FAIL = -1,
	MSG_ARG = 2,
};

enum e_validation
{
	ARG_SIZE = 2,
	PID = 1,
};

enum e_signal
{
	PENDING_NO = 0,
	PENDING_YES = 1,
	SET = 1,
	GET = -1,
};

int		arg_validation(int argc, char *pid_input);
void	cl_init(int server_pid);
void	cl_handle_msg(int input_pid, char *msg);
void	cl_sendingsignal(int input_pid, char *msg);
/* non-static client functions */

/* non-static server functions */

#endif