/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:17:21 by dmoroz            #+#    #+#             */
/*   Updated: 2024/01/20 13:34:40 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);

int	convert_arg_to_int(char *argv)
{
	int	i;
	int	pow;
	int	final_res;

	i = 0;
	pow = 1;
	final_res = 0;
	while (argv[i] != '\0')
	{
		i++;
	}
	i--;
	while (i >= 0)
	{
		if (argv[i] < '0' || argv[i] > '9')
		{
			return (-1);
		}
		final_res = final_res + (argv[i] - '0') * pow;
		i--;
		pow = pow * 10;
	}
	return (final_res);
}

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	if (argc != 3)
	{
		write(1, "Error. Expected 2 params: width and length of rectangle", 55);
		return (1);
	}
	x = convert_arg_to_int(argv[1]);
	y = convert_arg_to_int(argv[2]);
	if (x < 1 || y < 1)
	{
		write(1, "Error. Only digit chars are accepted", 36);
		return (1);
	}
	rush(x, y);
	return (0);
}
