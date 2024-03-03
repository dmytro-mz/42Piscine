/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_def.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:10:54 by dmoroz            #+#    #+#             */
/*   Updated: 2024/02/07 15:51:05 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_DEF_H
# define FUNC_DEF_H

# include "struct_def.h"

int		ft_power(int nb, int power);
int		read_first_line(int fd, t_legend *legend);
void	print_map_error(void);
int		fill_array(int **arr, int all[3], t_legend legend);
int		**create_arr(char *map_path, t_legend *legend, int *size, int *n_lines);
int		create_vectors(int **arr, int n_lines, int size);
void	set_legend_by_condition(t_legend *legend, char *leg, int n_lines,
			int i);
int		validate_legend(t_legend *legend);
int		parse_line(int *subarr, char *buffer, int size, t_legend legend);
int		parse_last_line(int *subarr, char *buffer, int size, t_legend legend);
int		min(int a, int b, int c);
void	print_map(int **arr, t_best_point best_point, t_legend legend,
			int *size_n_lines);
void	print_oneline_map(int *arr, t_legend legend, int size);
int		ft_strcat(char *str, char *buffer, int n_bytes_read);
int		ft_realloc(char **str, int length);
int		fill_array_from_str(char *str, int **arr, int all[3], t_legend legend);
int		**create_arr_from_stdin(char *map_path, t_legend *legend, int *size,
			int *n_lines);
int		fill_map_power(int **arr, t_best_point *best_point, int *size_n_lines,
			t_point point);
void	free_arr(int **arr, int n_lines);

#endif
