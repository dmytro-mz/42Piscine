/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:23:37 by dmoroz            #+#    #+#             */
/*   Updated: 2024/02/08 09:23:38 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my.h"

void	write_str(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(fd, str + i++, 1);
	}
}

void	write_tail(char *str, int n, int fd)
{
	write(fd, str, n);
	write_str("\n", fd);
	free(str);
}

int	write_inv_n_bytes_error(char *prog_name, char *char_n_bytes)
{
	write_str(basename(prog_name), 2);
	write_str(": ", 2);
	write_str("invalid number of bytes: '", 2);
	write_str(char_n_bytes, 2);
	write_str("'\n", 2);
	return (1);
}

void	write_file_header(char *file_name)
{
	write_str("==> ", 1);
	write_str(file_name, 1);
	write_str(" <==\n", 1);
}

int	write_open_file_error(char *prog_name, char *file_name)
{
	write_str(basename(prog_name), 2);
	write_str(": cannot open '", 2);
	write_str(file_name, 2);
	write_str("' for reading: ", 2);
	write_str(strerror(errno), 2);
	write_str("\n", 2);
	errno = 0;
	return (1);
}
