/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_def.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:10:45 by dmoroz            #+#    #+#             */
/*   Updated: 2024/02/07 15:10:47 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_DEF_H
# define STRUCT_DEF_H

typedef struct s_legend
{
	char	empty;
	char	obstacle;
	char	full;
}			t_legend;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_best_point
{
	t_point	point;
	int		power;
}			t_best_point;

#endif
