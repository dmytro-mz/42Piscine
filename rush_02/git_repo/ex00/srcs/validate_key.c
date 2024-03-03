/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:27:02 by dmoroz            #+#    #+#             */
/*   Updated: 2024/02/04 23:10:41 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_len_skip_zere(char *buffer, int *index, int *key_len)
{
	*key_len = 0;
	while (buffer[*index + *key_len] != ' ' && buffer[*index + *key_len] != ':')
	{
		if (buffer[*index + *key_len] < '0' || buffer[*index + *key_len] > '9')
			return (-1);
		if (buffer[*index + *key_len] == '0' && *key_len == 0)
			(*index)++;
		else
			(*key_len)++;
	}
	return (1);
}

int	check_ten_degree(char *buffer, int *index, int key_len)
{
	int	i;

	i = 1;
	while (i < key_len)
	{
		if (buffer[*index - key_len + i] != '0')
			return (0);
		i++;
	}
	return (1);
}

int	validate_key(char *buffer, int *index)
{
	int	key_len;

	if (check_len_skip_zere(buffer, index, &key_len) == -1)
		return (-1);
	*index += key_len;
	if (key_len == 0)
	{
		if (buffer[*index - 1] == '0')
			return (1);
		return (-1);
	}
	else if (key_len == 1 || (key_len == 2 && buffer[*index - key_len] == '1'))
		return (1);
	else if (key_len == 2 && buffer[*index - 1] == '0')
		return (1);
	else if (key_len == 3
		|| (key_len >= 4 && key_len <= 37 && (key_len - 1) % 3 == 0))
		if (buffer[*index - key_len] == '1')
			return (check_ten_degree(buffer, index, key_len));
	return (0);
}
