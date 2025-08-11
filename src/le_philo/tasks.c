/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 02:01:20 by moel-hib          #+#    #+#             */
/*   Updated: 2025/08/11 17:26:29 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	le_fork(t_philo *le_philo)
{
	if (le_philo->philo_id == le_philo->data->nm_philo)
	{
		pthread_mutex_lock(le_philo->fork_right);
		writer(le_philo, FORK);
		pthread_mutex_lock(le_philo->fork);
		writer(le_philo, FORK);
	}
	else
	{
		pthread_mutex_lock(le_philo->fork);
		writer(le_philo, FORK);
		pthread_mutex_lock(le_philo->fork_right);
		writer(le_philo, FORK);
	}
	le_philo->is_fork = 1;
	if (!le_philo->data->dead_flag && !le_philo->data->emergency_stop)
		return (0);
	return (1);
}

int	le_unfork(t_philo *le_philo)
{
	pthread_mutex_unlock(le_philo->fork);
	pthread_mutex_unlock(le_philo->fork_right);
	if (!le_philo->data->dead_flag && !le_philo->data->emergency_stop)
		return (0);
	return (1);
}

int	le_eat(t_philo *le_philo)
{
	if (!le_philo->data->dead_flag && !le_philo->data->emergency_stop)
	{
		writer(le_philo, EAT);
		mine_sleep(le_philo->data->tm_eat, le_philo);
		return (0);
	}
	return (1);
}

int	le_sleep(t_philo *le_philo)
{
	if (!le_philo->data->dead_flag && !le_philo->data->emergency_stop)
	{
		writer(le_philo, SLEEP);
		mine_sleep(le_philo->data->tm_sleep, le_philo);
		return (0);
	}
	return (1);
}

int	le_think(t_philo *le_philo)
{
	long	eat;
	long	sleep;

	eat = le_philo->time_to_eat;
	sleep = le_philo->time_to_sleep;
	if (!le_philo->data->dead_flag && !le_philo->data->emergency_stop)
	{
		writer(le_philo, THINK);
		if ((le_philo->data->nm_philo % 2)
			&& le_philo->time_to_eat >= le_philo->time_to_sleep)
			mine_sleep((eat - sleep) + 1, le_philo);
		return (0);
	}
	return (1);
}
