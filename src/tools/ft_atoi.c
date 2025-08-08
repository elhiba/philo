/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:59:27 by moel-hib          #+#    #+#             */
/*   Updated: 2025/08/08 22:58:53 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

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
	while (num[i] >= '0' && num[i] <= '9')
	{
		result = result * 10 + num[i] - 48;
		i++;
	}
	return (is_valid_input(result));
}
