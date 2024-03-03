/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:23:28 by dmoroz            #+#    #+#             */
/*   Updated: 2024/01/30 12:46:48 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	str_len_1(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		len;
	int		i;
	char	*copy;

	len = str_len_1(s);
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		copy[i] = s[i];
		i++;
	}
	return (copy);
}

struct s_stock_str	prepare_struct(char *s)
{
	struct s_stock_str	res;

	res.size = str_len_1(s);
	res.str = s;
	res.copy = ft_strdup(s);
	return (res);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*res;
	int					i;
	struct s_stock_str	last;

	res = (struct s_stock_str *)malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		res[i] = prepare_struct(av[i]);
		i++;
	}
	last.str = 0;
	res[i] = last;
	return (res);
}
