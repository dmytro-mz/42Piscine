/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:55:12 by dmoroz            #+#    #+#             */
/*   Updated: 2024/02/07 13:02:45 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	ft_strcat(char *str, char *buffer, int n_bytes_read)
{
	int	i;
	int	count;

	count = 0;
	while (str[count])
		count++;
	i = -1;
	while (++i < n_bytes_read)
		str[i + count] = buffer[i];
	str[count + i] = '\0';
	return (count + i);
}

int	ft_realloc(char **str, int length)
{
	char	*temp;
	int		i;

	i = -1;
	temp = (char *)malloc(sizeof(char) * length);
	if (!temp)
		return (-1);
	while ((*str)[++i])
		temp[i] = (*str)[i];
	temp[i] = '\0';
	free(*str);
	*str = temp;
	return (1);
}
