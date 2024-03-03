/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:05:23 by dmoroz            #+#    #+#             */
/*   Updated: 2024/01/28 20:05:49 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*get_substr_copy(char *str, int word_start, int word_end)
{
	char	*res;
	int		i;

	res = (char *)malloc(word_end - word_start + 1);
	i = 0;
	while (i < word_end - word_start)
	{
		res[i] = str[word_start + i];
		i++;
	}
	res[i] = 0;
	return (res);
}

int	is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (-1);
}

int	get_n_words(char *str, char *charset)
{
	int	word_start;
	int	w;
	int	i;

	word_start = -1;
	w = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_separator(str[i], charset) == -1 && word_start == -1)
			word_start = i;
		else if (is_separator(str[i], charset) == 1 && word_start >= 0)
		{
			w++;
			word_start = -1;
		}
		i++;
	}
	if (word_start >= 0)
		w++;
	return (w);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;
	int		word_start;
	int		w;

	res = (char **)malloc(8 * (get_n_words(str, charset) + 1));
	word_start = -1;
	w = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_separator(str[i], charset) == -1 && word_start == -1)
			word_start = i;
		else if (is_separator(str[i], charset) == 1 && word_start >= 0)
		{
			res[w++] = get_substr_copy(str, word_start, i);
			word_start = -1;
		}
		i++;
	}
	if (word_start >= 0)
		res[w++] = get_substr_copy(str, word_start, i);
	res[w] = NULL;
	return (res);
}
