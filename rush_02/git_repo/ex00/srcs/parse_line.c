/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:44:57 by dmoroz            #+#    #+#             */
/*   Updated: 2024/02/04 23:23:59 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func_def.h"

void	set_arr_ind(int *arr_type, int *arr_ind, int arr_type_v, int arr_ind_v)
{
	*arr_type = arr_type_v;
	*arr_ind = arr_ind_v;
}

void	choose_arr(char *buffer, int len, int *arr_type, int *arr_ind)
{
	if (len == 2)
	{
		if (*buffer < '2')
			set_arr_ind(arr_type, arr_ind, 0,
				10 * (*buffer - '0') + *(buffer + 1) - '0');
		else
			set_arr_ind(arr_type, arr_ind, 1, *buffer - '2');
	}
	else if (len == 1)
		set_arr_ind(arr_type, arr_ind, 0, *buffer - '0');
	else if (len == 3)
		set_arr_ind(arr_type, arr_ind, 1, 8);
	else
		set_arr_ind(arr_type, arr_ind, 2, len / 3 - 1);
}

int	parse_line(char ***dict, char *buffer, int start)
{
	int	i;
	int	arr_type;
	int	arr_ind;
	int	line_status;
	int	len;

	line_status = validate_line(buffer, start);
	if (line_status < 1)
		return (line_status);
	i = start;
	while (buffer[i] < '0' || buffer[i] > '9'
		|| (buffer[i] == '0' && buffer[i + 1] > '0' && buffer[i + 1] <= '9'))
		i++;
	len = get_key_len(buffer + i);
	choose_arr(buffer + i, len, &arr_type, &arr_ind);
	i += len;
	while (buffer[i] == ':' || buffer[i] == ' ')
		i++;
	len = get_value_len(buffer + i);
	dict[arr_type][arr_ind] = ft_strndup(buffer + i, len);
	if (!dict[arr_type][arr_ind])
		return (-1);
	return (0);
}
