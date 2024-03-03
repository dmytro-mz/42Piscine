/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:00:40 by dmoroz            #+#    #+#             */
/*   Updated: 2024/01/27 17:13:05 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_rules_col(int n, int *board, int *rules, int col);
int	check_rules_row(int n, int *board, int *rules, int row);

int	is_valid_val(int n, int *board, int *rules, int crc[2])
{
	int	i;

	i = 0;
	while (i < crc[1])
	{
		if (board[crc[0] * n + crc[1]] == board[crc[0] * n + i])
			return (-1);
		i++;
	}
	i = 0;
	while (i < crc[0])
	{
		if (board[crc[0] * n + crc[1]] == board[i * n + crc[1]])
			return (-1);
		i++;
	}
	if (crc[1] == n - 1)
		if (check_rules_row(n, board, rules, crc[0]) == -1)
			return (-1);
	if (crc[0] == n - 1)
		if (check_rules_col(n, board, rules, crc[1]) == -1)
			return (-1);
	return (1);
}

void	assign_next_row_col(int next_row_col[2], int curr_row_col[2], int n)
{
	next_row_col[0] = curr_row_col[0];
	next_row_col[1] = curr_row_col[1] + 1;
	if (next_row_col[1] >= n)
	{
		next_row_col[0]++;
		next_row_col[1] = 0;
	}
}

int	find_solution(int n, int *board, int *rules, int crc[2])
{
	int	val;
	int	res;
	int	nrc[2];

	assign_next_row_col(nrc, crc, n);
	val = 1;
	while (val <= n)
	{
		board[crc[0] * n + crc[1]] = val;
		if (is_valid_val(n, board, rules, crc) == 1)
		{
			if (crc[0] == n - 1 && crc[1] == n - 1)
				return (1);
			else
			{
				res = find_solution(n, board, rules, nrc);
			}
			if (res == 1)
				return (1);
		}
		val++;
	}
	return (0);
}
