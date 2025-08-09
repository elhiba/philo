/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:59:27 by moel-hib          #+#    #+#             */
/*   Updated: 2025/08/09 20:27:52 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	is_digit(char *input)
{
	while (*input)
	{
		if (!(*input >= '0' && *input <= '9'))
		{
			write(2, IN_NOT_VAL, ft_strlen(IN_NOT_VAL));
			return (-2);
		}
		input++;
	}
	return (0);
}

int	is_valid_input(long num)
{
	if (num <= 0)
	{
		write(2, IN_NOT_VAL, ft_strlen(IN_NOT_VAL));
		return (-2);
	}
	return (num);
}

long	ft_atoi(char *num)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	if (is_digit(num))
		return (-2);
	while (num[i] >= '0' && num[i] <= '9')
	{
		result = result * 10 + num[i] - 48;
		i++;
	}
	return (is_valid_input(result));
}
