/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:03:36 by moel-hib          #+#    #+#             */
/*   Updated: 2025/08/11 17:58:17 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	philo_job(t_philo *ptr)
{
	int	i;

	i = 0;
	if (ptr)
	{
		ptr = ptr->data->philo;
		while (i < ptr->data->nm_philo)
		{
			if (ptr->philo == (pthread_t)(-1))
				break ;
			if (pthread_join(ptr->philo, NULL))
				printf("Can't join with errno: %i\n", errno);
			ptr = ptr->next;
			i++;
		}
	}
}

void	philo_destroy(t_philo *ptr)
{
	int	i;

	i = 0;
	ptr = ptr->data->philo;
	if (pthread_mutex_destroy(ptr->pen))
		printf("Can't destroy with errno: %i\n", errno);
	while (i < ptr->data->nm_philo)
	{
		if (pthread_mutex_destroy(ptr->fork))
			printf("Can't destroy with errno: %i\n", errno);
		i++;
		ptr = ptr->next;
	}
}

void	philo_is_free(t_data *data)
{
	t_philo	*ptr;
	int		i;

	i = 0;
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

void	cleaner(t_data *data)
{
	philo_job(data->philo);
	philo_destroy(data->philo);
	philo_is_free(data);
}
