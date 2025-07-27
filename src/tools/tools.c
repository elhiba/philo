/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 03:24:01 by moel-hib          #+#    #+#             */
/*   Updated: 2025/07/28 00:23:17 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

// void	mine_sleep(t_philo *le_philo)
// {
// 	while (1)
// 	{
// 		if (le_philo->data->tm_sleep <= (get_time() - le_philo->time_to_sleep))
// 			break ;
// 		usleep(50);
// 	}
// }

void	writer(t_philo *data, char *message)
{
	pthread_mutex_lock(data->pen);
	if (!data->data->dead_flag)
		printf("%lld %i %s\n", get_time() - data->data->start_routine, data->philo_id, message);
	pthread_mutex_unlock(data->pen);
}

long long	get_time()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);

	return (tv.tv_sec * 1000LL + tv.tv_usec / 1000LL);
}
