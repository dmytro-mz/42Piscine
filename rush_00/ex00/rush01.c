/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:19:43 by dmoroz            #+#    #+#             */
/*   Updated: 2024/01/21 15:37:22 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_single_row(char left, char right, char middle, int x);

void	rush(int x, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		if (i == 0)
		{
			print_single_row('/', '\\', '*', x);
		}
		else if (i == y - 1)
		{
			print_single_row('\\', '/', '*', x);
		}
		else
		{
			print_single_row('*', '*', ' ', x);
		}
		i++;
	}
}
