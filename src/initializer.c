/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 16:31:32 by moel-hib          #+#    #+#             */
/*   Updated: 2025/07/28 02:54:00 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_data(t_data *data, char **av)
{
	memset(data, 0, sizeof(t_data));
	data->nm_philo = ft_atoi(av[0]);
	data->tm_die = ft_atoi(av[1]);
	data->tm_eat = ft_atoi(av[2]);
	data->tm_sleep = ft_atoi(av[3]);
	if (av[4])
		data->tm_each_philo_meat = ft_atoi(av[4]);
	else
		data->tm_each_philo_meat = -1;
}

t_philo	*init_philo(t_data *data)
{
	int		i;
	t_philo	*ptr;
	t_philo	*tmp;
	t_philo	*philo;

	i = 1;
	ptr = ft_calloc(1, sizeof(t_philo));
	philo = ptr;
	while (i < data->nm_philo)
	{
		tmp = ft_calloc(1, sizeof(t_philo));
		ptr->next = tmp;
		ptr = tmp;
		i++;
	}
	ptr->next = philo;
	return (philo);
}

void	philo_linker(t_philo *philo)
{
	t_philo	*ptr;
	int		i;

	i = 0;
	ptr = philo;
	while (i < ptr->data->nm_philo)
	{
		if (i != (ptr->data->nm_philo - 1))
		{
			ptr->fork_right = ptr->next->fork;
			ptr = ptr->next;
		}
		else
			ptr->fork_right = philo->fork;
		i++;
	}
}

void	fork_lock(t_data *data, t_philo *philo)
{
	int				i;
	t_philo			*ptr;
	pthread_mutex_t	*pen;

	i = 0;
	ptr = philo;
	pen = ft_calloc(1, sizeof(pthread_mutex_t));
	pthread_mutex_init(pen, NULL);
	data->start = false;
	while (i < data->nm_philo)
	{
		ptr->philo_id = i + 1;
		ptr->time_to_eat = data->tm_eat;
		ptr->time_to_sleep = data->tm_sleep;
		ptr->pen = pen;
		ptr->data = data;
		ptr->fork = ft_calloc(1, sizeof(pthread_mutex_t));
		pthread_mutex_init(ptr->fork, NULL);
		ptr = ptr->next;
		i++;
	}
	philo_linker(philo);
}
