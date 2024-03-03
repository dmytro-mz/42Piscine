/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:18:17 by dmoroz            #+#    #+#             */
/*   Updated: 2024/01/18 22:57:32 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdbool.h>
#include <unistd.h>

bool	cond_check(char a[10], int n)
{
	int	i;

	i = 0;
	while (i < (n - 1))
	{
		if (a[i] >= a[i + 1])
		{
			return (false);
		}
		i++;
	}
	return (true);
}

void	print_nums(char a[10], int n, bool *first_print)
{
	int	i;

	if ((*first_print) == false)
	{
		write(1, ", ", 2);
	}
	(*first_print) = false;
	i = 0;
	while (i < n)
	{
		write(1, &a[i], 1);
		i++;
	}
}

void	incr_nums(char a[10], int n, int depth)
{
	n--;
	a[n]++;
	if (a[n] > ('9' - depth))
	{
		if (n > 0)
		{
			incr_nums(a, n, depth + 1);
			a[n] = a[n - 1] + 1;
		}
	}
}

void	ft_print_combn(int n)
{
	char	a[10];
	int		i;
	bool	first_print;

	first_print = true;
	i = 0;
	while (i < 10)
	{
		a[i] = '0' + i;
		i++;
	}
	while (a[0] <= ('9' - n + 1))
	{
		if (cond_check(a, n))
		{
			print_nums(a, n, &first_print);
		}
		incr_nums(a, n, 0);
	}
}
