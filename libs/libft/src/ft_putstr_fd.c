/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:22:34 by umeneses          #+#    #+#             */
/*   Updated: 2023/12/12 14:47:50 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	size_t	index;
	size_t	len;
	char	c;

	if (!s)
		return (ft_putstr_fd("(null)", 1));
	index = 0;
	len = ft_strlen(s);
	while ((*s != '\0') && (index < len))
	{
		c = s[index];
		write(fd, &c, 1);
		index++;
	}
	return (len);
}
