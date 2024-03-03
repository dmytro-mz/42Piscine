/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:54:40 by dmoroz            #+#    #+#             */
/*   Updated: 2024/02/07 13:02:25 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	parse_line(int *subarr, char *buffer, int size, t_legend legend)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (buffer[i] == legend.obstacle)
			subarr[i] = -42;
		else if (buffer[i] == legend.empty && i < size - 2)
			subarr[i] = -1;
		else if (buffer[i] == legend.empty)
			subarr[i] = 1;
		else
			return (-1);
		i++;
	}
	return (1);
}

int	parse_last_line(int *subarr, char *buffer, int size, t_legend legend)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (buffer[i] == legend.obstacle)
			subarr[i] = -42;
		else if (buffer[i] == legend.empty)
			subarr[i] = 1;
		else
			return (-1);
		i++;
	}
	return (1);
}

int	free_buffer_on_error(char *buffer)
{
	free(buffer);
	return (-1);
}

int	fill_array(int **arr, int all[3], t_legend legend)
{
	char	*buffer;
	int		i;

	i = -1;
	buffer = (char *)malloc(sizeof(char) * all[2]);
	if (!buffer)
		return (-1);
	while (++i < all[1] && read(all[0], buffer, all[2]) == all[2])
	{
		if (buffer[all[2] - 1] != '\n')
			return (free_buffer_on_error(buffer));
		if (i < all[1] - 1)
		{
			if (parse_line(arr[i], buffer, all[2], legend) == -1)
				return (free_buffer_on_error(buffer));
		}
		else if (parse_last_line(arr[i], buffer, all[2], legend) == -1)
			return (free_buffer_on_error(buffer));
	}
	if (i != all[1] || read(all[0], buffer, all[2]) > 0)
		return (free_buffer_on_error(buffer));
	free(buffer);
	return (1);
}
