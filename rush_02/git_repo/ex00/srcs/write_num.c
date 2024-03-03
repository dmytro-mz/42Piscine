/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:58:35 by dmoroz            #+#    #+#             */
/*   Updated: 2024/02/04 23:07:11 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	write_string(char *str);
void	write_space(void);
void	write_and(void);
void	write_hyphen(void);
int		str_len(char *str);
int		str_cmp(char *a, char *b);
char	*get_base_degree_value(void);

void	write_tens(char degree_value[4], char ***dict)
{
	write_string(dict[1][(degree_value[1] - '0' - 2)]);
	if (degree_value[2] > '0')
	{
		write_hyphen();
		write_string(dict[0][(degree_value[2] - '0')]);
	}
}

void	write_hundred(char degree_value[4], char ***dict)
{
	write_string(dict[0][(degree_value[0] - '0')]);
	write_space();
	write_string(dict[1][8]);
	if (degree_value[1] > '0' || degree_value[2] > '0')
	{
		write_space();
		write_and();
		write_space();
	}
}

void	write_degree_value(char degree_value[4], char ***dict, int is_first)
{
	int	ind;

	if (str_cmp(degree_value, "000") == 0 && is_first == 1)
		write_string(dict[0][0]);
	else
	{
		if (degree_value[0] > '0')
			write_hundred(degree_value, dict);
		if (degree_value[1] > '1')
			write_tens(degree_value, dict);
		else if (degree_value[1] > '0' || degree_value[2] > '0')
		{
			ind = 10 * (degree_value[1] - '0') + degree_value[2] - '0';
			write_string(dict[0][ind]);
		}
	}
}

void	write_degree(int degree, char ***dict)
{
	write_space();
	write_string(dict[2][degree - 1]);
}

void	write_num(char *num, char ***dict, int is_first)
{
	int		degree;
	int		degree_value_size;
	int		i;
	char	*degree_value;

	degree_value = get_base_degree_value();
	degree = (str_len(num) + -1) / 3;
	degree_value_size = str_len(num) - (degree * 3);
	i = 0;
	while (i < degree_value_size)
	{
		degree_value[3 - degree_value_size + i] = num[i];
		i++;
	}
	if (is_first == 0 && str_cmp(degree_value, "000") != 0)
		write_space();
	write_degree_value(degree_value, dict, is_first);
	if (degree > 0)
	{
		if (degree_value[0] + degree_value[1] + degree_value[2] - '0' * 3 > 0)
			write_degree(degree, dict);
		free(degree_value);
		write_num(num + degree_value_size, dict, 0);
	}
}
