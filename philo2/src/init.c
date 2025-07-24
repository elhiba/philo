/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:25:14 by moel-hib          #+#    #+#             */
/*   Updated: 2025/07/24 15:51:14 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// info -> parse
// data -> philo
void	philo_create(t_philo_info *philo_info)
{
	t_philo_data	**philos;
	int				i;

	i = 0;
	philos = malloc(sizeof(t_philo_data *) * (philo_info->nb_of_philo + 1));
	while (i < philo_info->nb_of_philo)
	{
		philos[i] = malloc(sizeof(t_philo_data));
		memset(philos[i], 0, sizeof(t_philo_data));
		philos[i]->philo_id = i + 1;
		i++;
	}
	philo_info->philos = philos;
}

void	philo_init(t_philo_info *philo)
{
	int	i;

	i = 0;
	while (i < philo->nb_of_philo)
	{
		pthread_mutex_init(philo->philos[i]->left_fork, NULL);
	}
}
