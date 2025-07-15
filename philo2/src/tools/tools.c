/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 21:04:55 by moel-hib          #+#    #+#             */
/*   Updated: 2025/07/15 17:02:16 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/philo.h"

void	philo_parser(t_philo_info *philo_info, char **args)
{
	memset(philo_info, 0, sizeof(t_philo_info));
	philo_info->nb_of_philo = ft_atoi(args[0]);
	philo_info->tm_to_die = ft_atoi(args[1]);
	philo_info->nb_tm_to_eat = ft_atoi(args[2]);
	philo_info->tm_to_sleep = ft_atoi(args[3]);
	if (args[4])
		philo_info->nb_tm_to_eat = ft_atoi(args[4]);
}

t_philo_data	*philo_zone()
{
	t_philo_data	*philo_tracker;

	philo_tracker = malloc(sizeof(t_philo_data));
	if (!philo_tracker)
	{
		write(2, "malloc: failed\n", 15);
		return (NULL);
	}

	memset(philo_tracker, 0, sizeof(t_philo_data));
	pthread_mutex_init(&philo_tracker->left_fork, NULL);

	return (philo_tracker);
}

void	philo_creator(t_philo_data *philo_data, t_philo_info *philo_info)
{
	t_philo_data	*philo_tracker;
	int				i;

	i = 0;
//	*philo_data = philo_zone();
	philo_tracker = philo_data;
	while (i < philo_info->nb_of_philo)
	{
		philo_tracker->next = philo_zone();
		philo_tracker = philo_tracker->next;
		i++;
	}
}

void	philo_linker(t_philo_data *philo_data, t_philo_info *philo_info)
{
	t_philo_data	*philo_tracker;
	int				i;

	i = 0;
	memset(philo_data, 0, sizeof(t_philo_data));
	philo_creator(philo_data, philo_info);
	philo_tracker = philo_data;
	while (i < philo_info->nb_of_philo)
	{
		philo_tracker->philo_id = i + 1;
		philo_tracker->philo_start = current_time();
		philo_tracker = philo_tracker->next;
		i++;
	}
}
