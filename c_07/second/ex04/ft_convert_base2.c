/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:00:59 by dmoroz            #+#    #+#             */
/*   Updated: 2024/01/28 20:01:01 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_len(char *str);

void	skip_space_count_minus(char *str, int *i, int *minus)
{
	*i = 0;
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == ' ')
		(*i)++;
	*minus = 0;
	while (str[*i] == '-' || str[*i] == '+')
	{
		*minus += (str[*i] - '+') / 2;
		(*i)++;
	}
	*minus = ((*minus) % 2) * -2 + 1;
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	minus;
	int	res;
	int	j;
	int	base_len;

	skip_space_count_minus(str, &i, &minus);
	base_len = str_len(base);
	res = 0;
	while (1 == 1)
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (base[j] == str[i])
				break ;
			j++;
		}
		if (j == base_len)
			return (res);
		res = res * base_len + j * minus;
		i++;
	}
}

void	set_length_and_devider(long long *d, int *i, int nbr, int base_len)
{
	*d = 1;
	*i = 2;
	if (nbr < 0)
		*d = (*i)++ - 3;
	while (nbr / ((*d) * base_len) > 0)
	{
		*d *= base_len;
		(*i)++;
	}
}

char	*int_to_base(int nbr, char *base)
{
	char		*res;
	int			base_len;
	long long	divider;
	int			i;

	base_len = str_len(base);
	set_length_and_devider(&divider, &i, nbr, base_len);
	res = (char *)malloc(i);
	i = 0;
	if (nbr < 0)
	{
		res[i] = '-';
		i++;
	}
	while (divider != 0)
	{
		res[i] = base[nbr / divider];
		nbr = nbr % divider;
		divider /= base_len;
		i++;
	}
	res[i] = '\0';
	return (res);
}
