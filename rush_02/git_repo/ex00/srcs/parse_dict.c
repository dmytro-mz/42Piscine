/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:55:57 by dmoroz            #+#    #+#             */
/*   Updated: 2024/02/04 23:05:18 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 32768

void	write_dict_error(void);
void	write_error(void);
char	*ft_strndup(char *str, int len);
int		validate_line(char *buffer, int start);
int		validate_dict(char ***dict);
void	free_dict(char ***dict);
int		parse_line(char ***dict, char *buffer, int start);
char	***get_base_dict(void);

void	move_buffer(char *buffer, int start, int size)
{
	int	i;

	i = 0;
	while (start + i < size)
	{
		buffer[i] = buffer[start + i];
		i++;
	}
}

int	parse_buffer(char ***dict, char *buffer, int size)
{
	int	i;
	int	start_pos;
	int	status;

	start_pos = 0;
	i = 0;
	while (i < size)
	{
		if (buffer[i] == '\n')
		{
			status = parse_line(dict, buffer, start_pos);
			if (status == -1)
				return (-1);
			start_pos = i + 1;
		}
		i++;
	}
	if (start_pos < size)
		move_buffer(buffer, start_pos, size);
	return (size - start_pos);
}

void	do_on_error(char ***dict, int file_descriptor)
{
	write_dict_error();
	if (dict)
		free_dict(dict);
	if (file_descriptor >= 0)
		close(file_descriptor);
}

int	read_n_parse_file(char	***dict, int file_descriptor)
{
	int		buffer_pos;
	int		n_bites_read;
	char	buffer[BUF_SIZE];

	buffer_pos = 0;
	n_bites_read = read(file_descriptor, buffer, BUF_SIZE);
	while (n_bites_read > 0)
	{
		buffer_pos = parse_buffer(dict,
				buffer, n_bites_read + buffer_pos);
		if (buffer_pos == -1)
		{
			n_bites_read = -1;
			break ;
		}
		n_bites_read = read(file_descriptor,
				buffer + buffer_pos, BUF_SIZE - buffer_pos);
	}
	return (n_bites_read);
}

char	***parse_dict(char *dict_path)
{
	int		file_descriptor;
	int		n_bites_read;
	char	***dict;

	dict = get_base_dict();
	if (!dict)
		do_on_error(dict, -1);
	else
	{
		file_descriptor = open(dict_path, O_RDONLY);
		if (file_descriptor == -1)
		{
			do_on_error(dict, -1);
			return (NULL);
		}
		n_bites_read = read_n_parse_file(dict, file_descriptor);
		if (n_bites_read == -1 || validate_dict(dict) == -1)
		{
			do_on_error(dict, -1);
			dict = NULL;
		}
	}
	close(file_descriptor);
	return (dict);
}
