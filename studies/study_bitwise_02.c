/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   study_bitwise_02.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:50:51 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/25 19:01:24 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strreversing_order(char *string)
{
	int		index;
	int		char_position;
	char	temp;

	index = 0;
	char_position = strlen(string);
	while (index < char_position / 2)
	{
		temp = string[index];
		string[index] = string[char_position - index - 1];
		string[char_position - index -1] = temp;
		index++;
	}
	return (string);
}

char	*ft_dec_to_binary(int number)
{
	int		char_pos;
	int		index;
	char	*binary;

	char_pos = 0;
	index = 0;
	binary = calloc((32 + 1), sizeof(char));
	if (binary == NULL)
	{
		printf("Memory alllocation failed\n");
		exit(1);
	}
	while (number != 0)
	{
		binary[char_pos] = (number % 2) + '0';
		number = number / 2;
		char_pos++;
	}
	binary = ft_strreversing_order(binary);
	binary[char_pos] = '\0';
	return (binary);
}

int	main (void)
{
	int		number;
	char	*binary;

	number = 42;
	binary = ft_dec_to_binary(number);
	printf("number[%d] as a binary = %s\n", number, binary);
	return (0);
}