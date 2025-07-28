/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:03:36 by moel-hib          #+#    #+#             */
/*   Updated: 2025/07/28 06:29:45 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	philo_job(int i, t_philo *ptr)
{
	ptr = ptr->data->philo;
	while (i < ptr->data->nm_philo)
	{
		pthread_join(ptr->philo, NULL);
		ptr = ptr->next;
		i++;
	}
}

void	philo_destroy(int i, t_philo *ptr)
{
	ptr = ptr->data->philo;
	pthread_mutex_destroy(ptr->pen);
	while (i < ptr->data->nm_philo)
	{
		pthread_mutex_destroy(ptr->fork);
		i++;
		ptr = ptr->next;
	}

}

void	philo_is_free()
{

}

void	cleaner(t_data *data)
{
	t_philo	*ptr;
	int		i;

	i = 0;
	philo_job(i, data->philo);

	philo_destroy(i, data->philo);

	ptr = data->philo->next;
	free(data->philo->pen);
	while (i < data->nm_philo)
	{
		free(data->philo->fork);
		free(data->philo);
		data->philo = NULL;
		data->philo = ptr;
		if (i != (data->nm_philo - 1))
			ptr = ptr->next;
		i++;
	}
}
