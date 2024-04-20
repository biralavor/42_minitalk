/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:39:15 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/19 10:51:55 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize_int(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst-> next;
		size++;
	}
	return (size);
}
