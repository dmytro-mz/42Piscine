/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_unique_values.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:56:00 by dmoroz            #+#    #+#             */
/*   Updated: 2024/01/27 16:56:02 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_unique_values_row(int n, int *board, int row)
{
	int	col;
	int	val;
	int	is_found;

	val = 1;
	while (val <= n)
	{
		is_found = 0;
		col = 0;
		while (col < n)
		{
			if (board[row * n + col] == val)
			{
				is_found = 1;
				break ;
			}
			col++;
		}
		if (is_found == 0)
			return (-1);
		val++;
	}
	return (1);
}

int	check_unique_values_col(int n, int *board, int col)
{
	int	row;
	int	val;
	int	is_found;

	val = 1;
	while (val <= n)
	{
		is_found = 0;
		row = 0;
		while (row < n)
		{
			if (board[row * n + col] == val)
			{
				is_found = 1;
				break ;
			}
			row++;
		}
		if (is_found == 0)
			return (-1);
		val++;
	}
	return (1);
}
