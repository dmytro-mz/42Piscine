/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:59:33 by dmoroz            #+#    #+#             */
/*   Updated: 2024/01/27 16:59:52 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	validate_rules_str_size(char *argv, int n)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
		i++;
	if (i == n * 8 - 1)
		return (0);
	return (-1);
}

int	validate_rules_str(char *argv, int n)
{
	int	i;
	int	counter;

	if (validate_rules_str_size(argv, n) == -1)
		return (-1);
	counter = 0;
	i = 0;
	while (argv[i] != '\0')
	{
		if (i % 2 == 0)
		{
			if (argv[i] >= '1' && argv[i] <= '0' + n)
				counter++;
			else
				return (-1);
		}
		else
			if (argv[i] != ' ')
				return (-1);
		i++;
	}
	if (counter != n * 4)
		return (-1);
	return (0);
}

int	*parse_rules(char *argv, int n)
{
	int	i;
	int	*rules;
	int	status;

	status = validate_rules_str(argv, n);
	if (status == -1)
		rules = &status;
	else
	{
		rules = (int *)malloc(n * 4 * 4);
		i = 0;
		while (i < n * 4)
		{
			rules[i] = argv[i * 2] - '0';
			i++;
		}
	}
	return (rules);
}
