/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:59:24 by dmoroz            #+#    #+#             */
/*   Updated: 2024/02/04 23:24:10 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func_def.h"

void	write_space(void)
{
	write_string(" ");
}

void	write_new_line(void)
{
	write_string("\n");
}

void	write_and(void)
{
	write_string("and");
}

void	write_hyphen(void)
{
	write_string("-");
}
