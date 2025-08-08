/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 08:55:01 by moel-hib          #+#    #+#             */
/*   Updated: 2025/08/08 22:51:43 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	le_vrai_routine(t_philo *le_philo)
{
	le_fork(le_philo);
	le_philo->last_meal = get_time();
	le_eat(le_philo);
	if (le_unfork(le_philo))
		return (1);
	if (le_sleep(le_philo))
		return (1);
	if (le_think(le_philo))
		return (1);
	return (0);
}

void	*routini(void *tmp)
{
	t_philo		*le_philo;
	_Atomic int	i;

	i = 0;
	le_philo = (t_philo *)tmp;
	if (le_philo->philo_id == le_philo->data->nm_philo)
		le_philo->data->start = true;
	if ((le_philo->philo_id % 2) == 0)
		usleep(1000);
	le_philo->last_meal = get_time();
	if (le_special_philo(le_philo))
		return (NULL);
	while (!le_philo->data->dead_flag)
	{
		if (le_philo->many_eat == i)
		{
			le_philo->data->emergency_stop = 1;
			break ;
		}
		if (le_vrai_routine(le_philo))
			break ;
		i++;
	}
	return (NULL);
}

void	le_bigbang(t_philo *le_philo)
{
	_Atomic long	i;

	i = 0;
	while (le_philo->data && i < le_philo->data->nm_philo)
	{
		pthread_create(&le_philo->philo, NULL, routini, (void *)le_philo);
		le_philo->last_meal = get_time();
		le_philo = le_philo->next;
		i++;
	}
	while (!le_philo->data->start)
		usleep(10);
}

void	*monitor(void *sus)
{
	t_data			*amongus;
	t_philo			*le_philo;

	amongus = (t_data *)sus;
	amongus->start_routine = get_time();
	le_philo = amongus->philo;
	le_bigbang(le_philo);
	while (1)
	{
		if (le_philo->data->tm_die <= (get_time() - le_philo->last_meal))
		{
			la_mort(le_philo);
			break ;
		}
		if (le_philo->data->emergency_stop)
			break ;
		le_philo = le_philo->next;
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	pthread_t	t1;
	t_data		data;

	if (!(ac == 5 || ac == 6))
	{
		write(2, IN_ERROR, ft_strlen(IN_ERROR));
		return (1);
	}
	if (init_data(&data, ++av))
		return (2);
	data.philo = init_philo(&data);
	fork_lock(&data, (&data)->philo);
	if (data.failure)
		return (2);
	pthread_create(&t1, NULL, monitor, (void *)&data);
	pthread_join(t1, NULL);
	cleaner(&data);
	if (data.dead_flag)
		return (1);
	return (0);
}
