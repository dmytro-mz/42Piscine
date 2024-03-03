/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:11:37 by dmoroz            #+#    #+#             */
/*   Updated: 2024/01/24 16:12:11 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	str_size;

	str_size = 0;
	while (str[str_size] != '\0')
		str_size++;
	return (str_size);
}

void	ft_putstr(char *str)
{
	int	str_size;

	str_size = ft_strlen(str);
	write(1, str, str_size);
}
