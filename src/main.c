/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:06:47 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/15 13:26:53 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig)
{
	write(STDOUT_FILENO, "NOT today!!! HAHAHAHA\n", 22);
}

int	main(int argc, char **argv)
{
	char	*client_char;

	client_char = NULL;
	if (argc == 2)
	{
		client_char = argv[1];
		signal(SIGINT, handler);
		while (1)
		{
			ft_printf("client char = %c -> pid[%d}\n", client_char, getpid());
			sleep(1);
		}
		return (0);
	}
	else
	{
		ft_printf("Usage: ./a.out [char]\n");
		return (1);
	}
}
