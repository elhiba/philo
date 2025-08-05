/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 08:55:01 by moel-hib          #+#    #+#             */
/*   Updated: 2025/08/05 22:57:26 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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

		le_fork(le_philo);

		le_philo->last_meal = get_time();

		le_eat(le_philo);

		if (le_unfork(le_philo))
			break ;

		if (le_sleep(le_philo))
			break ;

		if (le_think(le_philo))
			break ;

		i++;
	}
	return (NULL);
}

void	*monitor(void *sus)
{
	t_data			*amongus;
	t_philo			*le_philo;
	_Atomic long	i;

	i = 0;
	amongus = (t_data *)sus;
	le_philo = amongus->philo;
	amongus->start_routine = get_time();
	while (le_philo->data && i < le_philo->data->nm_philo)
	{
		pthread_create(&le_philo->philo, NULL, routini, (void *)le_philo);
		le_philo->last_meal = get_time();
		le_philo = le_philo->next;
		i++;
	}

	while (!le_philo->data->start)
		usleep(10);

	while(1)
	{
		if (le_philo->data->tm_die <= (get_time() - le_philo->last_meal))
		{
			writer(le_philo, DIE);
			le_philo->data->dead_flag = 1;
			break ;
		}
		if (le_philo->data->emergency_stop)
			break;
		le_philo = le_philo->next;
	}
	return (NULL);
}

int main(int ac, char **av)
{
	pthread_t	t1;
	t_data		data;

	if (!(ac == 5 || ac == 6))
	{
		write(2, IN_ERROR, ft_strlen(IN_ERROR));
		exit(1);
	}

	init_data(&data, ++av);
	data.philo = init_philo(&data);
	fork_lock(&data, (&data)->philo);

	pthread_create(&t1, NULL, monitor, (void *)&data);
	pthread_join(t1, NULL);

	cleaner(&data);

	return (0);
}
