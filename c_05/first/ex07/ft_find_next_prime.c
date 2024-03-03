/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:07:24 by dmoroz            #+#    #+#             */
/*   Updated: 2024/01/26 11:15:37 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	sqrt_est(int nb)
{
	int	min;
	int	max;
	int	p;

	min = 1;
	max = 46340;
	if (max > nb)
		max = nb / 2;
	while (max - min > 3)
	{
		p = max - (max - min) / 2;
		if (p * p > nb)
			max = p;
		else
			min = p;
	}
	return (max);
}

int	ft_is_prime(int nb)
{
	int	n;
	int	est_sqrt;

	if (nb == 2 || nb == 3 || nb == 5)
		return (1);
	if (nb < 2 || nb % 2 == 0 || nb % 3 == 0 || nb % 5 == 0)
		return (0);
	n = 5;
	est_sqrt = sqrt_est(nb);
	while (n < est_sqrt)
	{
		if (nb % n == 0 || nb % (n + 2) == 0)
			return (0);
		n += 6;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	n;

	if (nb % 6 == 5)
		n = nb;
	else if (nb % 6 == 1 || nb % 6 == 0)
	{
		if (ft_is_prime(nb + 1 - (nb % 6)) == 1)
			return (nb + 1 - (nb % 6));
		n = nb + 5 - (nb % 6);
	}
	else
		n = nb + 6 - (nb % 6) - 1;
	while (1 == 1)
	{
		if (ft_is_prime(n) == 1)
			return (n);
		if (ft_is_prime(n + 2) == 1)
			return (n + 2);
		n += 6;
	}
}
