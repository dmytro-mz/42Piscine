/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:05:19 by wkornato          #+#    #+#             */
/*   Updated: 2024/02/07 15:49:31 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	reopen(int fd, char *map_path)
{
	char	buffer[1];
	int		chars_read;

	close(fd);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (-1);
	chars_read = read(fd, buffer, 1);
	if (chars_read == -1)
		return (-1);
	while (buffer[0] != '\n')
	{
		chars_read = read(fd, buffer, 1);
		if (chars_read == -1)
			return (-1);
	}
	return (fd);
}

int	create_vectors(int **arr, int n_lines, int size)
{
	int	i;

	i = -1;
	while (++i < n_lines)
	{
		arr[i] = (int *)malloc(sizeof(int) * (size));
		if (!arr[i])
		{
			while (i >= 0)
				arr[i--] = NULL;
			return (-1);
		}
	}
	return (0);
}

int	count_second_line(int fd)
{
	char	buffer[1];
	int		chars_read;
	int		count;

	chars_read = read(fd, buffer, 1);
	if (chars_read == -1)
		return (-1);
	count = 1;
	while (buffer[0] != '\n' && chars_read > 0)
	{
		chars_read = read(fd, buffer, 1);
		if (chars_read == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	**close_file_on_error_2(int fd, int **arr, int n_lines)
{
	close(fd);
	if (arr)
		free_arr(arr, n_lines);
	return (NULL);
}

int	**create_arr(char *map_path, t_legend *legend, int *size, int *n_lines)
{
	int	**arr;
	int	all[3];

	all[0] = open(map_path, O_RDONLY);
	if (all[0] == -1)
		return (NULL);
	all[1] = read_first_line(all[0], legend);
	if (all[1] == -1)
		return (close_file_on_error_2(all[0], NULL, 0));
	arr = (int **)malloc(sizeof(int *) * all[1]);
	if (!arr)
		return (close_file_on_error_2(all[0], NULL, 0));
	all[2] = count_second_line(all[0]);
	if (all[2] < 2)
		return (close_file_on_error_2(all[0], arr, 0));
	if (create_vectors(arr, all[1], (all[2] - 1)) == -1)
		return (close_file_on_error_2(all[0], arr, 0));
	all[0] = reopen(all[0], map_path);
	if (fill_array(arr, all, *legend) == -1)
		return (close_file_on_error_2(all[0], arr, all[1]));
	close(all[0]);
	*size = all[2];
	*n_lines = all[1];
	return (arr);
}
