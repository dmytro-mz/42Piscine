/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:56:31 by dmoroz            #+#    #+#             */
/*   Updated: 2024/01/27 16:56:33 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	print_board(int n, int *board)
{
	int	i;
	int	j;
	int	char_ind;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (j != 0)
				write(1, " ", 1);
			char_ind = board[i * n + j] + '0';
			write(1, &char_ind, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	free_mem(int *board, int *rules)
{
	if (board != rules)
	{
		free(board);
		free(rules);
	}
	else
		free(board);
}

void	do_on_error(int *board, int *rules)
{
	free_mem(board, rules);
	write(1, "Error\n", 6);
}
