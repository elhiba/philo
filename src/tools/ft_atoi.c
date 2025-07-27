/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:59:27 by moel-hib          #+#    #+#             */
/*   Updated: 2025/07/26 17:25:14 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_atoi(char *num)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (num[i] >= '0' && num[i] <= '9')
	{
		result = result * 10 + num[i] - 48;
		i++;
	}
	return (result);
}
