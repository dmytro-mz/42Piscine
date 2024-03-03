/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:21:53 by dmoroz            #+#    #+#             */
/*   Updated: 2024/02/07 17:27:56 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <string.h>
#include <unistd.h>

#define BUFF_SIZE 1

void	write_str(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(fd, str + i++, 1);
	}
}

void	print_error(char *prog_name, char *file_name)
{
	write_str(basename(prog_name), 2);
	write_str(": ", 2);
	write_str(file_name, 2);
	write_str(": ", 2);
	write_str(strerror(errno), 2);
	write_str("\n", 2);
	errno = 0;
}

int	read_file(int fd, char *prog_name, char *file_name)
{
	char	buffer[BUFF_SIZE];
	int		n_bites_read;

	n_bites_read = read(fd, buffer, BUFF_SIZE);
	while (n_bites_read > 0)
	{
		write(1, buffer, n_bites_read);
		n_bites_read = read(fd, buffer, BUFF_SIZE);
	}
	if (n_bites_read < 0)
		print_error(prog_name, file_name);
	return (n_bites_read < 0);
}

int	process_file(char *file_name, char *prog_name)
{
	int	res;
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		print_error(prog_name, file_name);
		return (1);
	}
	res = read_file(fd, prog_name, file_name);
	close(fd);
	return (res);
}

int	main(int ac, char *av[])
{
	int	res;
	int	i;

	i = 1;
	res = 0;
	if (ac == 1)
		return (read_file(0, av[0], ""));
	else
	{
		while (i < ac)
		{
			if (av[i][0] == '-' && av[i][1] == '\0')
				res = res | read_file(0, av[0], "");
			else
				res = res | process_file(av[i], av[0]);
			i++;
		}
	}
	return (res);
}
