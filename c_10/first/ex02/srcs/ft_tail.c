/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:30:58 by dmoroz            #+#    #+#             */
/*   Updated: 2024/02/08 09:41:48 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my.h"

void	mem_copy(char *buffer, int n_bytes, int n_bytes_read)
{
	int	i;

	i = -1;
	while (++i < n_bytes)
		buffer[i] = buffer[i + n_bytes_read - n_bytes];
}

void	do_tail(int fd, int n_bytes)
{
	char	*buffer;
	int		n_bytes_read;
	int		pad;

	buffer = (char *)malloc(sizeof(char) * n_bytes * 2);
	if (!buffer)
		return ;
	n_bytes_read = read(fd, buffer, n_bytes * 2);
	if (n_bytes_read <= n_bytes)
		return (write_tail(buffer, n_bytes_read, 1));
	pad = 0;
	while (n_bytes_read > 0)
	{
		mem_copy(buffer, n_bytes, pad + n_bytes_read);
		n_bytes_read = read(fd, buffer + n_bytes, n_bytes);
		pad = n_bytes;
	}
	write_tail(buffer, n_bytes, 1);
}

int	process_file(char *file_name, char *prog_name, int nth, int n_bytes)
{
	int	fd;

	if (file_name[0] == '-' && file_name[1] == 0)
	{
		fd = 0;
		file_name = "standard input";
	}
	else
	{
		fd = open(file_name, O_RDONLY);
	}
	if (fd == -1)
		return (write_open_file_error(prog_name, file_name));
	if (nth >= 0)
	{
		// if (nth > 0)
		// 	write_str("\n", 1);
		write_file_header(file_name);
	}
	do_tail(fd, n_bytes);
	if (fd > 1)
		close(fd);
	return (0);
}

int	parse_n_bytes(char *char_n_bytes)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (char_n_bytes[i])
	{
		if (char_n_bytes[i] < '0' || char_n_bytes[i] > '9')
			return (-1);
		res = res * 10 + char_n_bytes[i++] - '0';
	}
	return (res);
}
