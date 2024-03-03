/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:26:15 by dmoroz            #+#    #+#             */
/*   Updated: 2024/01/30 12:26:42 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

int	str_len(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	print_stock_str(struct s_stock_str tt)
{
	int		d;
	int		size;
	char	c;

	write(1, tt.str, str_len(tt.str));
	write(1, "\n", 1);
	d = 1;
	while (tt.size / (d * 10) > 0)
		d *= 10;
	size = tt.size;
	while (d > 0)
	{
		c = size / d + '0';
		write(1, &c, 1);
		size %= d;
		d /= 10;
	}
	write(1, "\n", 1);
	write(1, tt.copy, str_len(tt.copy));
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	while ((*par).str != 0)
		print_stock_str(*(par++));
}
