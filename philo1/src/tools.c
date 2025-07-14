/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 03:24:01 by moel-hib          #+#    #+#             */
/*   Updated: 2025/07/10 04:00:24 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

long long	get_time()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);

	return (tv.tv_sec * 1000LL + tv.tv_usec / 1000LL);
}
