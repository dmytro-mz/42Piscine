/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arr_from_stdin.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:54:29 by dmoroz            #+#    #+#             */
/*   Updated: 2024/02/07 15:55:53 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

#define BUFF_SIZE 100
#define STR_SIZE 8096

char	*read_stdin(void)
{
	char	*res;
	char	buffer[BUFF_SIZE];
	int		n_bytes_read;
	int		res_len;

	res_len = STR_SIZE;
	res = (char *)malloc(sizeof(char) * res_len);
	if (!res)
		return (NULL);
	res[0] = 0;
	n_bytes_read = read(1, buffer, BUFF_SIZE);
	while (n_bytes_read > 0)
	{
		if (ft_strcat(res, buffer, n_bytes_read) + BUFF_SIZE > res_len)
		{
			res_len *= 2;
			if (ft_realloc(&res, res_len) == -1)
				return (NULL);
		}
		n_bytes_read = read(1, buffer, 90);
	}
	if (n_bytes_read == -1)
		return (NULL);
	return (res);
}

int	str_first_line(char *str, t_legend *legend)
{
	int		n_lines;
	char	tmp_leg[3];
	int		i;
	int		j;

	j = -1;
	i = 0;
	n_lines = 0;
	while (str[++j] != '\n')
	{
		if (str[j] == 0)
			return (-1);
		if (str[j] >= '0' && str[j] <= '9' && i == 0)
			n_lines = n_lines * 10 + str[j] - '0';
		else
		{
			if (i == 3)
				return (-1);
			tmp_leg[i++] = str[j];
		}
	}
	set_legend_by_condition(legend, tmp_leg, n_lines, i);
	if (n_lines / ft_power(10, 3 - i) == 0 || validate_legend(legend) == -1)
		return (-1);
	return (n_lines / ft_power(10, 3 - i));
}

int	str_count_second_line(char *str)
{
	int	i;
	int	count;

	i = -1;
	while (str[++i] != '\n')
		if (str[i] == 0)
			return (-1);
	count = 0;
	while (str[i + ++count] != '\n')
		if (str[i + count] == 0)
			return (-1);
	return (count);
}

int	**close_file_on_error_3(char *str, int **arr, int n_lines)
{
	free(str);
	if (arr)
		free_arr(arr, n_lines);
	return (NULL);
}

int	**create_arr_from_stdin(char *map_path, t_legend *legend, int *size,
		int *n_lines)
{
	int		**arr;
	int		all[3];
	char	*str;

	(void)map_path;
	str = read_stdin();
	all[1] = str_first_line(str, legend);
	if (all[1] == -1)
		return (close_file_on_error_3(str, NULL, 0));
	arr = (int **)malloc(sizeof(int *) * all[1]);
	if (!arr)
		return (close_file_on_error_3(str, NULL, 0));
	all[2] = str_count_second_line(str);
	if (all[2] < 2)
		return (close_file_on_error_3(str, arr, 0));
	if (create_vectors(arr, all[1], (all[2] - 1)) == -1)
		return (close_file_on_error_3(str, arr, 0));
	if (fill_array_from_str(str, arr, all, *legend) == -1)
		return (close_file_on_error_3(str, arr, all[1]));
	*size = all[2];
	*n_lines = all[1];
	free(str);
	return (arr);
}
