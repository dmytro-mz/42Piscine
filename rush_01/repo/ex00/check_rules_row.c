/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rules_row.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:55:38 by dmoroz            #+#    #+#             */
/*   Updated: 2024/01/27 16:55:40 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_rules_row_left(int n, int *board, int *rules, int row)
{
	int	counter;
	int	prev_h;
	int	col;

	counter = 1;
	prev_h = board[row * n];
	col = 1;
	while (col < n)
	{
		if (board[row * n + col] > prev_h)
		{
			counter++;
			prev_h = board[row * n + col];
		}
		col++;
	}
	if (counter != rules[n * 2 + row])
		return (-1);
	return (1);
}

int	check_rules_row_right(int n, int *board, int *rules, int row)
{
	int	counter;
	int	prev_h;
	int	col;

	counter = 1;
	prev_h = board[row * n + n - 1];
	col = n - 2;
	while (col >= 0)
	{
		if (board[row * n + col] > prev_h)
		{
			counter++;
			prev_h = board[row * n + col];
		}
		col--;
	}
	if (counter != rules[n * 3 + row])
		return (-1);
	return (1);
}

int	check_rules_row(int n, int *board, int *rules, int row)
{
	if (check_rules_row_left(n, board, rules, row) == -1)
		return (-1);
	if (check_rules_row_right(n, board, rules, row) == -1)
		return (-1);
	return (1);
}
