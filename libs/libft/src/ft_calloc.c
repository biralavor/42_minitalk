/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:09:44 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/12 22:15:21 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n_items, size_t size)
{
	void	*result;
	int		safety_arg;
	size_t	int_min;

	int_min = -2147483648;
	if (n_items == 0 && size == 0)
		return (malloc(0));
	if (n_items == int_min || size == int_min)
		return (NULL);
	safety_arg = n_items * size;
	if (safety_arg != 0 && (safety_arg / n_items) != size)
		return (NULL);
	result = malloc(safety_arg);
	if (!result)
		return (NULL);
	ft_bzero(result, safety_arg);
	return (result);
}

// static void	*malloc_bzeroing(size_t safety_arg);

// void	*ft_calloc(size_t n_items, size_t size)
// {
// 	void	*result;
// 	size_t	safety_arg;

// 	if (n_items <= 0 || size <= 0)
// 		return (NULL);
// 	else
// 		safety_arg = n_items * size;
// 	if (((safety_arg / size) != n_items) && ((safety_arg / n_items) != size))
// 		return (NULL);
// 	result = malloc_bzeroing(safety_arg);
// 	return (result);
// }

// static void	*malloc_bzeroing(size_t safety_arg)
// {
// 	char	*array;
// 	size_t	index;

// 	array = (char *)malloc(safety_arg);
// 	if (array == NULL)
// 	{
// 		free (array);
// 		return (NULL);
// 	}
// 	index = 0;
// 	while (index < safety_arg)
// 	{
// 		array[index] = '\0';
// 		index++;
// 	}
// 	return ((void *)array);
// }
