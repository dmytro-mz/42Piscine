/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:12:53 by dmoroz            #+#    #+#             */
/*   Updated: 2024/02/02 12:12:55 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int	check_argc(int argc)
{
	if (argc == 2)
		return (1);
	if (argc == 1)
		write(2, "File name missing.\n", 19);
	else
		write(2, "Too many arguments.\n", 20);
	return (0);
}

int	write_file_to_stdout(int file_descriptor, char buffer[BUF_SIZE])
{
	int	n_bites_read;

	n_bites_read = read(file_descriptor, buffer, BUF_SIZE);
	while (n_bites_read > 0)
	{
		write(1, buffer, n_bites_read);
		n_bites_read = read(file_descriptor, buffer, BUF_SIZE);
	}
	return (n_bites_read);
}

int	main(int argc, char *argv[])
{
	int		file_descriptor;
	char	buffer[BUF_SIZE];
	int		n_bites_read;

	if (!check_argc(argc))
		return (1);
	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return (1);
	}
	n_bites_read = write_file_to_stdout(file_descriptor, buffer);
	if (n_bites_read == -1)
	{
		write(2, "Cannot read file.\n", 18);
		close(file_descriptor);
		return (1);
	}
	close(file_descriptor);
	return (0);
}
