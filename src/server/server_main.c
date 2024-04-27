/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:06:25 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/27 17:18:37 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sv_init(void)
{
	ft_putstr_fd(GREEN, STDOUT_FILENO);
	ft_putstr_fd("Server is starting...\n", STDOUT_FILENO);
	ft_putstr_fd("Your Server PID is >>> ", STDOUT_FILENO);
	ft_putstr_fd(CYAN, STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putstr_fd(GREEN, STDOUT_FILENO);
	ft_putstr_fd("\nServer is running \\o/\n", STDOUT_FILENO);
}

static void	client_signal_handler(int sig, siginfo_t *info, void *ucontext)
{
	static int	received_bit;
	static char	c;

	(void)ucontext;
	if (sig == SIGUSR1)
		c += 0 << received_bit;
	if (sig == SIGUSR2)
		c += 1 << received_bit;
	received_bit++;
	if (received_bit == BYTE_SIZE)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		received_bit = SIG_DEFAULT;
		c = SIG_DEFAULT;
	}
	if (kill(info->si_pid, SIGUSR1) == SERVER_FAIL)
		ft_error_msg("Server failed to send signal to Client.\n");
}

int	main(void)
{
	struct sigaction	server_act;

	sv_init();
	sigemptyset(&server_act.sa_mask);
	server_act.sa_sigaction = client_signal_handler;
	server_act.sa_flags = SA_SIGINFO;
	if ((sigaction(SIGUSR1, &server_act, NULL) == SERVER_FAIL)
		|| (sigaction(SIGUSR2, &server_act, NULL) == SERVER_FAIL))
		ft_error_msg("Server signal failed.\n");
	while (WAIT)
		pause();
	exit(EXIT_SUCCESS);
}
