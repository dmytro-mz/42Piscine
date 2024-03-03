/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_first_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:05:10 by wkornato          #+#    #+#             */
/*   Updated: 2024/02/07 15:57:55 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	set_legend_values(t_legend *legend, char e, char o, char f)
{
	legend->empty = e;
	legend->obstacle = o;
	legend->full = f;
}

void	set_legend_by_condition(t_legend *legend, char *leg, int n_lines, int i)
{
	if (i == 3)
		set_legend_values(legend, leg[0], leg[1], leg[2]);
	else if (i == 2)
		set_legend_values(legend, (n_lines % 10) + '0', leg[0], leg[1]);
	else if (i == 1)
		set_legend_values(legend, (n_lines % 100 / 10) + '0', (n_lines % 10)
			+ '0', leg[0]);
	else
		set_legend_values(legend, (n_lines % 1000 / 100) + '0', (n_lines % 100
				/ 10) + '0', (n_lines % 10) + '0');
}

int	validate_legend(t_legend *legend)
{
	if (legend->empty == legend->obstacle)
		return (-1);
	if (legend->empty == legend->full)
		return (-1);
	if (legend->obstacle == legend->full)
		return (-1);
	return (1);
}

int	read_first_line(int fd, t_legend *legend)
{
	char	buffer[1];
	int		n_lines;
	char	tmp_leg[3];
	int		i;

	i = 0;
	n_lines = 0;
	while (read(fd, buffer, 1) == 1 && buffer[0] != '\n' && buffer[0] != 4)
	{
		if (buffer[0] >= '0' && buffer[0] <= '9' && i == 0)
			n_lines = n_lines * 10 + buffer[0] - '0';
		else
		{
			if (i == 3)
				return (-1);
			tmp_leg[i++] = buffer[0];
		}
	}
	if (n_lines == 0 || buffer[0] != '\n')
		return (-1);
	set_legend_by_condition(legend, tmp_leg, n_lines, i);
	if (n_lines / ft_power(10, 3 - i) == 0 || validate_legend(legend) == -1)
		return (-1);
	return (n_lines / ft_power(10, 3 - i));
}
