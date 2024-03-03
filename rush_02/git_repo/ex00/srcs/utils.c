/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:57:39 by dmoroz            #+#    #+#             */
/*   Updated: 2024/02/04 22:10:12 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	write_string(char *str)
{
	write(1, str, str_len(str));
}

int	str_cmp(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	return (a[i] - b[i]);
}

char	*ft_strndup(char *str, int len)
{
	char	*res;
	int		i;

	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*str_cpy(char *str)
{
	int		i;
	char	*res;
	int		len;

	len = str_len(str);
	res = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i <= len)
	{
		res[i] = str[i];
		i++;
	}
	return (res);
}
