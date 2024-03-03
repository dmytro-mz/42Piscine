/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:33:58 by dmoroz            #+#    #+#             */
/*   Updated: 2024/01/21 15:11:51 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_single_row(char left, char right, char middle, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
		{
			ft_putchar(left);
		}
		else if (i == x - 1)
		{
			ft_putchar(right);
		}
		else
		{
			ft_putchar(middle);
		}
		i++;
	}
	write(1, "\n", 1);
}
