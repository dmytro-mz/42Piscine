/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:15:43 by dmoroz            #+#    #+#             */
/*   Updated: 2024/01/24 19:42:33 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	if (c >= 9 && c <= 13)
		return (1);
	else if (c == ' ')
		return (1);
	return (0);
}

int	str_to_num(char *str)
{
	int	result;
	int	digit;

	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		digit = *str - '0';
		result = result * 10 + digit;
		str++;
	}
	return (result);
}

int	get_sign_value(char c)
{
	if (c == '-')
		return (1);
	else if (c == '+')
		return (0);
	return (-1);
}

int	ft_atoi(char *str)
{
	int		i;
	int		n_minuses;

	n_minuses = 0;
	i = 0;
	while (is_space(str[i]) == 1)
		i++;
	while (get_sign_value(str[i]) >= 0)
	{
		n_minuses += get_sign_value(str[i]);
		i++;
	}
	return (((n_minuses % 2) * -2 + 1) * str_to_num(&str[i]));
}
