/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:36:10 by dmoroz            #+#    #+#             */
/*   Updated: 2024/01/19 12:07:32 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_numbers(void)
{
	char	start_char;
	char	end_char;

	start_char = '0';
	end_char = '9';
	while (start_char <= end_char)
	{
		write(1, &start_char, 1);
		start_char++;
	}
}
