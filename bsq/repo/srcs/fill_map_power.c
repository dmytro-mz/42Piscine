/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_power.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkornato <wkornato@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:05:00 by wkornato          #+#    #+#             */
/*   Updated: 2024/02/07 15:05:01 by wkornato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	update_best_point(t_best_point *best_point, int power, t_point point)
{
	if (best_point->power < power || (best_point->power == power
			&& best_point->point.x > point.x) || (best_point->power == power
			&& best_point->point.x == point.x && best_point->point.y > point.y))
	{
		best_point->point = point;
		best_point->power = power;
	}
	return (power);
}

int	fill_map_power(int **arr, t_best_point *best_point, int *size_n_lines,
		t_point point)
{
	int	a;
	int	b;
	int	c;

	if (point.x >= size_n_lines[1])
		return (0);
	else if (point.y >= size_n_lines[0] - 1)
		return (0);
	else if (arr[point.x][point.y] >= 0)
		return (update_best_point(best_point, arr[point.x][point.y], point));
	point.y++;
	a = fill_map_power(arr, best_point, size_n_lines, point);
	point.x++;
	c = fill_map_power(arr, best_point, size_n_lines, point);
	point.y--;
	b = fill_map_power(arr, best_point, size_n_lines, point);
	point.x--;
	if (arr[point.x][point.y] == -42)
		arr[point.x][point.y] = 0;
	else if (arr[point.x][point.y] == -1)
		arr[point.x][point.y] = min(a, b, c) + 1;
	return (update_best_point(best_point, arr[point.x][point.y], point));
}
