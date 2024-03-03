/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:52:47 by dmoroz            #+#    #+#             */
/*   Updated: 2024/02/04 23:23:48 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "func_def.h"

int	check_chars(char *num, int *i, int *commas)
{
	*i = 0;
	*commas = 0;
	while (num[*i] != '\0')
	{
		if (!(num[*i] >= '0' && num[*i] <= '9') && num[*i] != ',')
		{
			write_error();
			return (-1);
		}
		if (num[*i] == ',')
			(*commas)++;
		(*i)++;
	}
	if (*i == 0)
	{
		write_error();
		return (-1);
	}
	return (1);
}

int	check_comma_pos(char *num, int len)
{
	int	i;

	i = 4;
	while (i < len)
	{
		if (num[len - i] != ',')
			return (-1);
		i += 4;
	}
	return (1);
}

void	clear_commas(char *num)
{
	int	i;
	int	n_commas;

	i = 0;
	n_commas = 0;
	while (num[i] != '\0')
	{
		if (num[i] == ',')
			n_commas++;
		else if (n_commas > 0)
			num[i - n_commas] = num[i];
		i++;
	}
	num[i - n_commas] = num[i];
}

int	cope_commas(int commas, char *num, int i)
{
	if (commas > 0)
	{
		if (i / 4 != commas || check_comma_pos(num, i) == -1)
		{
			write_error();
			return (-1);
		}
		clear_commas(num);
	}
	return (1);
}

char	*normalize_num(char *num)
{
	int	i;
	int	commas;

	num = str_cpy(num);
	if (*num == '+')
		num++;
	while (num[0] == '0' && num[1] >= '0' && num[1] <= '9')
		num++;
	if (check_chars(num, &i, &commas) == -1)
		return (NULL);
	if (cope_commas(commas, num, i) == -1)
		return (NULL);
	i = str_len(num);
	if (i > 39)
	{
		write_dict_error();
		return (NULL);
	}
	return (num);
}
