/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:49:06 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/27 18:20:48 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libs/libft/includes/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <fcntl.h>
# include <stdbool.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define COLOR_RESET "\033[0m"

enum e_server
{
	SERVER_FAIL = -1,
	RESET = 0,
	WAIT = 1,
};

enum e_client
{
	CLIENT_FAIL = -1,
	ARG_MSG = 2,
	BYTE_SIZE = 8,
	BIT = 1,
};

enum e_validation
{
	ARG_SIZE = 3,
	ARG_PID = 1,
};

enum e_signal
{
	SIG_PENDING_NO = 0,
	SIG_PENDING_YES = 1,
	SIG_DEFAULT = 0,
	SIG_SET = 1,
	SIG_GET = -1,
};

int		arg_validation(int argc, char *pid_input);
/* arguments validation */

void	cl_init(int server_pid, char *msg);
bool	cl_sigaction_init(void);
/* client initialization functions */

void	cl_msg_header(int server_pid);
void	cl_msg_tail(int server_pid);
/* header and tail messages layout */

void	cl_sendingsignal(int server_pid, char c_msg);
void	cl_send_bit(int server_pid, char c_msg);
/* client signal functions */

/* non-static server functions */

#endif