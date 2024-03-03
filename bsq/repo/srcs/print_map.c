/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:55:04 by dmoroz            #+#    #+#             */
/*   Updated: 2024/02/07 13:02:39 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	print_map(int **arr, t_best_point best_point, t_legend legend,
		int *size_n_lines)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size_n_lines[1])
	{
		j = -1;
		while (++j < size_n_lines[0] - 1)
		{
			if (arr[i][j] == 0 || arr[i][j] == -42)
				write(1, &legend.obstacle, 1);
			else if (i >= best_point.point.x && i < best_point.point.x
				+ best_point.power && j >= best_point.point.y
				&& j < best_point.point.y + best_point.power && arr[i][j] > 0)
				write(1, &legend.full, 1);
			else if (arr[i][j] > 0)
				write(1, &legend.empty, 1);
			else
				write(1, "#", 1);
		}
		write(1, "\n", 1);
	}
}

void	print_oneline_map(int *arr, t_legend legend, int size)
{
	int	j;
	int	first_empty_seen;

	first_empty_seen = 0;
	j = -1;
	while (++j < size - 1)
	{
		if (arr[j] == 0 || arr[j] == -42)
			write(1, &legend.obstacle, 1);
		else if (arr[j] > 0 && first_empty_seen == 0)
			write(1, &legend.full, ++first_empty_seen);
		else if (arr[j] > 0)
			write(1, &legend.empty, 1);
		else
			write(1, "#", 1);
	}
	write(1, "\n", 1);
}
