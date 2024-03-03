/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:36:10 by dmoroz            #+#    #+#             */
/*   Updated: 2024/01/18 16:54:29 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	start_char;
	char	end_char;

	start_char = 'z';
	end_char = 'a';
	while (start_char >= end_char)
	{
		write(1, &start_char, 1);
		start_char--;
	}
}
