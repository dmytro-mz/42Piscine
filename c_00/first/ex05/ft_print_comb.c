/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:37:56 by dmoroz            #+#    #+#             */
/*   Updated: 2024/01/18 18:16:40 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdbool.h>

void	print_nums(char first, char second, char third, bool is_first)
{
	char	sep1;
	char	sep2;

	sep1 = ',';
	sep2 = ' ';
	if (is_first == false)
	{
		write(1, &sep1, 1);
		write(1, &sep2, 1);
	}
	write(1, &first, 1);
	write(1, &second, 1);
	write(1, &third, 1);
}

void	inc_numbers(char *first, char *second, char *third)
{
	(*third)++;
	if ((*third) > '9')
	{
		(*second)++;
		if ((*second) > '8')
		{
			(*first)++;
			(*second) = (*first) + 1;
		}
		(*third) = (*second) + 1;
	}
}

void	ft_print_comb(void)
{
	char	first;
	char	second;
	char	third;

	first = '0';
	second = '1';
	third = '3';
	print_nums('0', '1', '2', true);
	while (first < '8')
	{
		if (first != second && first != third && second != third)
		{
			print_nums(first, second, third, false);
		}
		inc_numbers(&first, &second, &third);
	}
}
