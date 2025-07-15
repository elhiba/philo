/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   someft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 20:52:28 by moel-hib          #+#    #+#             */
/*   Updated: 2025/07/15 04:20:03 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/philo.h"

int	ft_atoi(char *number)
{
	int	result;
	int	index;

	result = 0;
	index = 0;
	while (number[index])
	{
		result = result * 10 + number[index] - 48;
		index++;
	}
	return (result);
}

long long current_time()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);

	return (tv.tv_sec * 1000LL + tv.tv_usec / 1000LL);
}
