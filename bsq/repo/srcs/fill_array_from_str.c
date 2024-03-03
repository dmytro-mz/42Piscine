/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array_from_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkornato <wkornato@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:04:50 by wkornato          #+#    #+#             */
/*   Updated: 2024/02/07 15:04:53 by wkornato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	fill_array_from_str(char *str, int **arr, int all[3], t_legend legend)
{
	int	row;
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	row = -1;
	while (++row < all[1])
	{
		if (str[i + all[2]] != '\n')
			return (-1);
		if (row < all[1] - 1)
		{
			if (parse_line(arr[row], str + i + 1, all[2], legend) == -1)
				return (-1);
		}
		else if (parse_last_line(arr[row], str + i + 1, all[2], legend) == -1)
			return (-1);
		i += all[2];
	}
	if (str[i + 1] != 0)
		return (-1);
	return (1);
}
