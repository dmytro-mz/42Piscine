/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_error_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:59:39 by dmoroz            #+#    #+#             */
/*   Updated: 2024/02/04 21:59:40 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	write_string(char *str);

void	write_error(void)
{
	write_string("Error\n");
}

void	write_dict_error(void)
{
	write_string("Dict Error\n");
}
