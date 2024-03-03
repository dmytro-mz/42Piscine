/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:13:47 by dmoroz            #+#    #+#             */
/*   Updated: 2024/01/24 16:13:50 by dmoroz           ###   ########.fr       */
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

	max_base = 1;
	while ((nb / max_base > 9) || (nb / max_base < -9))
	{
		max_base = max_base * 10;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
	}
	while (max_base > 1)
	{
		dig_to_write = nb / max_base;
		nb = nb % max_base;
		max_base = max_base / 10;
		write_dig(dig_to_write);
	}
	write_dig(nb);
}
