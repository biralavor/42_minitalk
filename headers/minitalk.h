/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:49:06 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/20 17:41:11 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libs/libft/includes/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <fcntl.h>

enum e_server
{
	BYTE_SIZE = 8,
	BIT = 1,
	SERVER_FAIL = -1,
	RESET = 0,
	WAIT = 1,
};

enum e_client
{
	CLIENT_FAIL = -1,
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
};

int	arg_validation(int argc, char *pid_input);
/* non-static client functions */


/* non-static server functions */

#endif