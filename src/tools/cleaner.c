/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:03:36 by moel-hib          #+#    #+#             */
/*   Updated: 2025/07/28 00:21:49 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/philo.h"

void	philo_job()
{

}

void	cleaner(t_data *data)
{
	t_philo	*ptr;
	int		i;
	
	i = 0;
	ptr = data->philo;
	while (i < data->nm_philo)
	{
		pthread_join(ptr->philo, NULL);
		ptr = ptr->next;
		i++;
	}

	i = 0;
	ptr = data->philo;
	pthread_mutex_destroy(ptr->pen);
	while (i < data->nm_philo)
	{
		pthread_mutex_destroy(ptr->fork);
		pthread_mutex_destroy(ptr->time_to_die);
		pthread_mutex_destroy(ptr->tm_eat);

		i++;
		ptr = ptr->next;
	}

	i = 0;
	ptr = data->philo->next;
	free(data->philo->pen);
	while (i < data->nm_philo)
	{
		free(data->philo->fork);
		free(data->philo->time_to_die);
		free(data->philo->tm_eat);
		free(data->philo);
		data->philo = NULL;
		data->philo = ptr;
		if (i != (data->nm_philo - 1))
			ptr = ptr->next;
		i++;
	}
}
