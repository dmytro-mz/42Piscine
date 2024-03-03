/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:21:05 by dmoroz            #+#    #+#             */
/*   Updated: 2024/01/19 18:24:26 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	write_dig(short d)
{
	if (d < 0)
	{
		d = d * -1;
	}
	d = d + 48;
	write(1, &d, 1);
}

void	ft_putnbr(int nb)
{
	int		max_base;
	short	dig_to_write;

	max_base = 1000000000;
	write(1, "\"", 1);
	if (nb < 0)
	{
		write(1, "-", 1);
	}
	while (nb / 10 != 0)
	{
		dig_to_write = nb / max_base;
		nb = nb % max_base;
		max_base = max_base / 10;
		if (dig_to_write != 0)
		{
			write_dig(dig_to_write);
		}
	}
	write_dig(nb);
	write(1, "\"", 1);
}
