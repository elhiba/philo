/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 08:55:01 by moel-hib          #+#    #+#             */
/*   Updated: 2025/07/28 06:35:13 by moel-hib         ###   ########.fr       */
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
		usleep(60);
	le_philo->last_meal = get_time();
	while (!le_philo->data->dead_flag)
	{
		//if (le_philo->data->tm_each_philo_meat != -1)
		//{
		//	if (le_philo->data->tm_each_philo_meat == i)
		//		//--le_philo->data->tm_each_philo_meat;
		//}

		if (le_philo->philo_id == le_philo->data->nm_philo)
		{
			pthread_mutex_lock(le_philo->fork_right);
			writer(le_philo, "has taken a fork");
			pthread_mutex_lock(le_philo->fork);
			writer(le_philo, "has taken a fork");
		}
		else
		{
			pthread_mutex_lock(le_philo->fork);
			writer(le_philo, "has taken a fork");
			pthread_mutex_lock(le_philo->fork_right);
			writer(le_philo, "has taken a fork");
		}

		le_philo->last_meal = get_time();

		writer(le_philo, "is eating");
		mine_sleep(le_philo->data->tm_eat * 1000);

		if (le_philo->philo_id == le_philo->data->nm_philo)
		{
			pthread_mutex_unlock(le_philo->fork);
			pthread_mutex_unlock(le_philo->fork_right);
		}
		else
		{
			pthread_mutex_unlock(le_philo->fork_right);
			pthread_mutex_unlock(le_philo->fork);
		}

		writer(le_philo, "is sleeping");
		mine_sleep(le_philo->data->tm_sleep * 1000);

		writer(le_philo, "is thinking");

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
		usleep(50);

	//i = 0;
	while(1)
	{
	//	if (le_philo->data->tm_each_philo_meat == i)
	//		break ;
		if (le_philo->data->tm_die <= (get_time() - le_philo->last_meal))
		{
			writer(le_philo, "died");
			le_philo->data->dead_flag = 1;
			break ;
		}
		//++i;
		le_philo = le_philo->next;
	}
	return NULL;
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
