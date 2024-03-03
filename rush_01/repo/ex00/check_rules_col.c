/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rules_col.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:55:05 by dmoroz            #+#    #+#             */
/*   Updated: 2024/01/27 16:55:11 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_rules_col_up(int n, int *board, int *rules, int col)
{
	int	counter;
	int	prev_h;
	int	row;

	counter = 1;
	prev_h = board[col];
	row = 1;
	while (row < n)
	{
		if (board[row * n + col] > prev_h)
		{
			counter++;
			prev_h = board[row * n + col];
		}
		row++;
	}
	if (counter != rules[col])
		return (-1);
	return (1);
}

int	check_rules_col_down(int n, int *board, int *rules, int col)
{
	int	counter;
	int	prev_h;
	int	row;

	counter = 1;
	prev_h = board[(n - 1) * n + col];
	row = n - 2;
	while (row >= 0)
	{
		if (board[row * n + col] > prev_h)
		{
			counter++;
			prev_h = board[row * n + col];
		}
		row--;
	}
	if (counter != rules[n + col])
		return (-1);
	return (1);
}

int	check_rules_col(int n, int *board, int *rules, int col)
{
	if (check_rules_col_up(n, board, rules, col) == -1)
		return (-1);
	if (check_rules_col_down(n, board, rules, col) == -1)
		return (-1);
	return (1);
}
