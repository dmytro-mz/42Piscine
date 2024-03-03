/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:41:47 by dmoroz            #+#    #+#             */
/*   Updated: 2024/01/23 19:41:49 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_size;
	unsigned int	src_size;
	unsigned int	i;

	dest_size = 0;
	while (dest[dest_size] != '\0')
		dest_size++;
	src_size = 0;
	while (src[src_size] != '\0')
		src_size++;
	if (size <= dest_size)
		return (src_size + size);
	i = dest_size;
	while (i < size - 1 && src[i - dest_size] != '\0')
	{
		dest[i] = src[i - dest_size];
		i++;
	}
	dest[i] = '\0';
	return (src_size + dest_size);
}
