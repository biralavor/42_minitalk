/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:44:14 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/22 17:45:04 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error_msg(char *string)
{
	ft_putstr_fd("\033[0;31m<< Error >> ", STDERR_FILENO);
	ft_putstr_fd(string, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
