/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:04:39 by dmoroz            #+#    #+#             */
/*   Updated: 2024/01/26 11:04:41 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	min;
	int	max;
	int	p;

	if (nb < 1)
		return (0);
	min = 1;
	max = 46340;
	while (max - min > 3)
	{
		p = max - (max - min) / 2;
		if (p * p > nb)
			max = p;
		else
			min = p;
	}
	while (min <= max)
	{
		if (min * min == nb)
			return (min);
		min++;
	}
	return (0);
}
