/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:36:10 by dmoroz            #+#    #+#             */
/*   Updated: 2024/01/18 16:48:13 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	start_char;
	char	end_char;

	start_char = 'a';
	end_char = 'z';
	while (start_char <= end_char)
	{
		write(1, &start_char, 1);
		start_char++;
	}
}
