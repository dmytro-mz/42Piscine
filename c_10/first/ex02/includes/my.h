/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:23:32 by dmoroz            #+#    #+#             */
/*   Updated: 2024/02/08 09:26:05 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_H
# define MY_H

# include <errno.h>
# include <fcntl.h>
# include <libgen.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	write_str(char *str, int fd);
void	write_tail(char *str, int n, int fd);
int		write_inv_n_bytes_error(char *prog_name, char *char_n_bytes);
void	write_file_header(char *file_name);
int		write_open_file_error(char *prog_name, char *file_name);
void	mem_copy(char *buffer, int n_bytes, int n_bytes_read);
void	do_tail(int fd, int n_bytes);
int		process_file(char *file_name, char *prog_name, int nth, int n_bytes);
int		parse_n_bytes(char *char_n_bytes);

#endif