/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_base_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:29:26 by dmoroz            #+#    #+#             */
/*   Updated: 2024/02/04 23:23:00 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "func_def.h"

char	**get_base_array(int size)
{
	char	**arr;
	int		i;

	arr = (char **)malloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
		arr[i++] = NULL;
	return (arr);
}

char	***get_base_dict(void)
{
	char	***dict;

	dict = (char ***)malloc(sizeof(char **) * 3);
	if (!dict)
	{
		write_error();
		return (NULL);
	}
	dict[0] = get_base_array(20);
	dict[1] = get_base_array(9);
	dict[2] = get_base_array(12);
	return (dict);
}
