/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:39:23 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/20 17:41:30 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	client_signal(int input_pid, char *msg)
{
	struct sigaction	client_act;

	sigemptyset(&client_act.sa_mask);
	client_act.sa_flags = SA_SIGINFO;
	client_act.sa_sigaction = handler_act;
	if ((sigaction(SIGUSR1, &client_act, NULL) == CLIENT_FAIL)
		|| (sigaction(SIGUSR2, &client_act, NULL) == CLIENT_FAIL))
		ft_msg_error("Error >> Server signal failed.\n");


}
