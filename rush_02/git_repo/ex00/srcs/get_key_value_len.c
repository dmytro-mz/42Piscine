/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key_value_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:57:06 by dmoroz            #+#    #+#             */
/*   Updated: 2024/02/04 22:57:08 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_key_len(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] >= '0' && buffer[i] <= '9')
		i++;
	return (i);
}

int	get_value_len(char *buffer)
{
	int	i;
	int	length;

	i = 0;
	while (buffer[i] != '\n')
	{
		if (buffer[i] != ' ')
			length = i + 1;
		i++;
	}
	return (length);
}
