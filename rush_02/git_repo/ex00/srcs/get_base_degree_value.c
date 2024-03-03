/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_base_degree_value.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 23:01:16 by dmoroz            #+#    #+#             */
/*   Updated: 2024/02/04 23:07:34 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*get_base_degree_value(void)
{
	char	*degree_value;

	degree_value = (char *)malloc(sizeof(char) * 4);
	degree_value[0] = '0';
	degree_value[1] = '0';
	degree_value[2] = '0';
	degree_value[3] = '\0';
	return (degree_value);
}
