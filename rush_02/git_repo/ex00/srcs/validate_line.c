/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:27:11 by dmoroz            #+#    #+#             */
/*   Updated: 2024/02/04 23:23:39 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func_def.h"

void	skip_space(char *buffer, int *index)
{
	while (buffer[*index] == ' ')
		(*index)++;
}

int	validate_value(char *buffer, int *index)
{
	int	i;
	int	non_space;

	non_space = 0;
	i = 0;
	while (buffer[*index + i] != '\n')
	{
		if (buffer[*index + i] < 32 || buffer[*index + i] > 126)
			return (-1);
		if (buffer[*index + i] >= 33 && buffer[*index + i] <= 126)
			non_space++;
		i++;
	}
	if (non_space == 0)
		return (-1);
	return (1);
}

int	validate_line(char *buffer, int start)
{
	int	i;
	int	status;

	i = start;
	if (buffer[i] == '\n')
		return (0);
	skip_space(buffer, &i);
	if (buffer[i] == '+')
		i++;
	status = validate_key(buffer, &i);
	if (status < 0)
		return (status);
	skip_space(buffer, &i);
	if (buffer[i++] != ':')
		return (-1);
	skip_space(buffer, &i);
	if (validate_value(buffer, &i) == -1)
		return (-1);
	return (status);
}

int	validate_dict(char ***dict)
{
	int	i;

	if (!dict)
		return (-1);
	if (!dict[0] || !dict[1] || !dict[2])
		return (-1);
	i = 0;
	while (i < 20)
		if ((!dict[0][i]) || str_len(dict[0][i++]) == 0)
			return (-1);
	i = 0;
	while (i < 9)
		if ((!dict[1][i]) || str_len(dict[1][i++]) == 0)
			return (-1);
	i = 0;
	while (i < 12)
		if ((!dict[2][i]) || str_len(dict[2][i++]) == 0)
			return (-1);
	return (1);
}
