/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:07:56 by dmoroz            #+#    #+#             */
/*   Updated: 2024/01/24 20:10:35 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	str_to_base_num(char *str, char *base, int base_len)
{
	int	i;
	int	j;
	int	res;

	res = 0;
	i = 0;
	while (1 == 1)
	{
		j = 0;
		while (j < base_len)
		{
			if (str[i] == base[j])
				break ;
			j++;
		}
		if (j == base_len)
			break ;
		res = res * base_len + j;
		i++;
	}
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	base_len;
	int	n_minuses;
	int	sign;

	n_minuses = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	while ((str[i] == '+') || (str[i] == '-'))
	{
		n_minuses += (str[i] - '+') / 2;
		i++;
	}
	base_len = get_base_len(base);
	if (base_len < 2)
		return (0);
	sign = (n_minuses % 2) * -2 + 1;
	return (sign * str_to_base_num(&str[i], base, base_len));
}
