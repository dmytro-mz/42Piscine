/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:42:20 by dmoroz            #+#    #+#             */
/*   Updated: 2024/01/28 18:44:15 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	copy_strs_to_str(char **strs, char *res, int size, char *sep)
{
	int	i;
	int	g;
	int	j;

	i = 0;
	g = 0;
	while (i < size)
	{
		if (i != 0)
		{
			j = 0;
			while (sep[j] != '\0')
				res[g++] = sep[j++];
		}
		j = 0;
		while (strs[i][j] != '\0')
			res[g++] = strs[i][j++];
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		total_len;
	char	*res;

	if (size == 0)
	{
		res = (char *)malloc(1);
		res[0] = '\0';
		return (res);
	}
	total_len = (size - 1) * str_len(sep);
	i = 0;
	while (i < size)
		total_len += str_len(strs[i++]);
	res = (char *)malloc(total_len + 1);
	copy_strs_to_str(strs, res, size, sep);
	return (res);
}
