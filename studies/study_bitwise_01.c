/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   study_bitwise_01.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:50:51 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/25 18:53:25 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../includes/libft.h"
#include <stdlib.h>

/* This approach do not convert the binary into a STRING. */
/* It may fail.*/

int	main (void)
{
	int 	number;
	int		nbr_remainder;
	int		index;
	int		binary;

	number = 42;
	index = 1;
	binary = 0;
	while (number != 0)
	{
		nbr_remainder = number % 2;
		number = number / 2;
		binary = binary + (nbr_remainder * index);
		if (number == 0)
			break ;
		index = index * 10;
	}
	ft_printf("final binary: %d\n", binary);
	return (0);
}
