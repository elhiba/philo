/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 03:24:01 by moel-hib          #+#    #+#             */
/*   Updated: 2025/08/07 01:55:27 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	mine_sleep(long tm_sleep, t_philo *le_philo)
{
	long	start_time;

	start_time = get_time();
	while (tm_sleep >= (get_time() - start_time) && !le_philo->data->dead_flag
		&& !le_philo->data->emergency_stop)
		usleep(200);
}

int	writer(t_philo *data, char *message)
{
	pthread_mutex_lock(data->pen);
	if (!data->data->dead_flag)
		printf("%.6ld\t%.3i %s\n", get_time() - data->data->start_routine,
			data->philo_id, message);
	pthread_mutex_unlock(data->pen);
	if (data->data->dead_flag)
		return (1);
	return (0);
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000l + tv.tv_usec / 1000l);
}
