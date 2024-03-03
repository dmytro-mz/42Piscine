/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:08:04 by dmoroz            #+#    #+#             */
/*   Updated: 2024/01/23 17:38:38 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>

void	print_mem_address(void *addr)
{
	uintptr_t	addr_int;
	char		mem_char[16];
	int			i;

	addr_int = (uintptr_t)addr;
	i = 15;
	while (i >= 0)
	{
		mem_char[i] = "0123456789abcdef"[addr_int >> (4 * (15 - i)) & 0xF];
		i--;
	}
	write(1, mem_char, 16);
	write(1, ": ", 2);
}

void	print_hex_chars(void *addr)
{
	int	i;

	i = 0;
	while (i < 16 && ((char *)addr)[i] != '\0')
	{
		if ((i) % 2 == 0 && i > 0)
			write(1, " ", 1);
		write(1, &"0123456789abcdef"[((char *)addr)[i] >> 4], 1);
		write(1, &"0123456789abcdef"[((char *)addr)[i] & 0xF], 1);
		i++;
	}
	if (i < 16)
	{
		write(1, "00", 2);
		i++;
		while (i < 16)
		{
			if ((i) % 2 == 0 && i > 0)
				write(1, " ", 1);
			write(1, "  ", 2);
			i++;
		}
	}
	write(1, " ", 1);
}

void	print_text(void *addr)
{
	int	i;

	i = 0;
	while (i < 16 && ((char *)addr)[i] != '\0')
	{
		if (((char *)addr)[i] >= 32 && ((char *)addr)[i] <= 126)
			write(1, &((char *)addr)[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	if (i < 16)
		write(1, ".", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (i > 0)
			write(1, "\n", 1);
		print_mem_address(addr + i);
		print_hex_chars(addr + i);
		print_text(addr + i);
		i += 16;
	}
	return (addr);
}
