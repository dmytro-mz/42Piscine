/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:31:30 by dmoroz            #+#    #+#             */
/*   Updated: 2024/02/04 23:19:01 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_arr(char **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(arr[i++]);
	free(arr);
}

void	free_dict(char ***dict)
{
	if (dict[0])
		free_arr(dict[0], 20);
	if (dict[1])
		free_arr(dict[1], 9);
	if (dict[2])
		free_arr(dict[2], 12);
}
