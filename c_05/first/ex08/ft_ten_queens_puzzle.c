/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:24:20 by dmoroz            #+#    #+#             */
/*   Updated: 2024/01/26 11:29:23 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_board(int board[10])
{
	int	i;
	int	char_ind;

	i = 0;
	while (i < 10)
	{
		char_ind = board[i] + '0';
		write(1, &char_ind, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	check_validity(int b[10], int c, int p)
{
	int	j;

	j = 1;
	while (c - j >= 0)
	{
		if (p == b[c - j] || p == b[c - j] - j || p == b[c - j] + j)
			return (0);
		j++;
	}
	return (1);
}

int	stage(int board[10], int col) // [0, 1, 2, 3, _, _, _, _, _], 4
{
	int	pos;
	int	res;

	res = 0;
	pos = 0;
	while (pos < 10)
	{
		if (check_validity(board, col, pos) == 1)
		{
			board[col] = pos;
			if (col < 9)
				res += stage(board, col + 1);
			else
			{
				print_board(board);
				res++;
			}
		}
		pos++;
	}
	return (res);
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	pos;
	int	res;

	res = 0;
	pos = 0;
	while (pos < 10)
	{
		board[0] = pos;
		res += stage(board, 1);
		pos++;
	}
	return (res);
}
