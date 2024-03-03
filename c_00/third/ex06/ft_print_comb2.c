/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:10:55 by dmoroz            #+#    #+#             */
/*   Updated: 2024/01/18 19:32:41 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_nums(short a, short b)
{
	char	to_print;

	write(1, ", ", 2);
	to_print = 48 + (a / 10);
	write(1, &to_print, 1);
	to_print = 48 + (a % 10);
	write(1, &to_print, 1);
	write(1, " ", 1);
	to_print = 48 + (b / 10);
	write(1, &to_print, 1);
	to_print = 48 + (b % 10);
	write(1, &to_print, 1);
}

void	inc_nums(short *a, short *b)
{
	(*b)++;
	if ((*b) > 99)
	{
		(*a)++;
		(*b) = (*a) + 1;
	}
}

void	ft_print_comb2(void)
{
	short	f;
	short	s;

	write(1, "00 01", 5);
	f = 0;
	s = 2;
	while (f < 99)
	{
		print_nums(f, s);
		inc_nums(&f, &s);
	}
}
