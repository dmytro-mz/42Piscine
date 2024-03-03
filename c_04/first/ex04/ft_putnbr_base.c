/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:14:01 by dmoroz            #+#    #+#             */
/*   Updated: 2024/01/24 19:20:07 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	get_base_len(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (-1);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;
	int	max_base;

	base_len = get_base_len(base);
	if (base_len < 2)
		return ;
	max_base = 1;
	if (nbr < 0)
	{
		write(1, "-", 1);
		max_base = -1;
	}
	while ((max_base <= nbr && nbr >= 0) || (max_base >= nbr && nbr < 0))
		max_base *= base_len;
	max_base /= base_len;
	while (max_base != 0)
	{
		write(1, &base[nbr / max_base], 1);
		nbr -= max_base * (nbr / max_base);
		max_base /= base_len;
	}
}
