/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 08:55:01 by moel-hib          #+#    #+#             */
/*   Updated: 2025/07/26 09:54:56 by moel-hib         ###   ########.fr       */
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

	i = 0;
	ptr = malloc(sizeof(t_philo));
	if (!ptr)
		return (NULL);
	philo = ptr;
	while (i < data->nm_philo)
	{
		tmp = malloc(sizeof(t_philo));
		if (!tmp)
			return (NULL);
		memset(ptr, 0, sizeof(t_philo));
		ptr->next = tmp;
		ptr = tmp;
		i++;
	}
	return (philo);
}

void	fork_lock(t_data *data, t_philo *philo)
{
	int				i;
	t_philo			*ptr;
	pthread_mutex_t	pen;

	i = 0;
	ptr = philo;
	//pen = NULL;
	pthread_mutex_init(&pen, NULL);
	while (i < data->nm_philo)
	{
		ptr->philo_id = i + 1;
		ptr->time_to_eat = data->tm_eat;
		ptr->time_to_sleep = data->tm_sleep;

		ptr->pen = &pen;
		ptr->data = data;

		ptr->time_to_die = malloc(sizeof(pthread_mutex_t));
		ptr->tm_eat = malloc(sizeof(pthread_mutex_t));
		ptr->fork = malloc(sizeof(pthread_mutex_t));

		if (!ptr->time_to_die || !ptr->tm_eat || !ptr->fork)
			return ;

		pthread_mutex_init(ptr->time_to_die, NULL);
		pthread_mutex_init(ptr->tm_eat, NULL);
		pthread_mutex_init(ptr->fork, NULL);

		ptr = ptr->next;
		i++;
	}

	i = 0;
	ptr = philo;
	while (i < data->nm_philo)
	{
		if (i != (data->nm_philo - 1))
		{
			ptr->fork_right = ptr->next->fork;
			ptr = ptr->next;
		}
		else
			ptr->fork_right = philo->fork;
		i++;
	}
}

void	*routini(void *tmp)
{
	t_philo	*le_philo;

	le_philo = (t_philo *)tmp;

	pthread_mutex_lock(le_philo->fork);
	writer(le_philo, "has taken a fork");
	pthread_mutex_lock(le_philo->fork_right);
	writer(le_philo, "has taken a fork");

	pthread_mutex_lock(le_philo->time_to_die);
	le_philo->last_meal = get_time();
	pthread_mutex_unlock(le_philo->time_to_die);

	writer(le_philo, "is eating");

	usleep(le_philo->data->tm_sleep * 1000ll);
	writer(le_philo, "is sleeping");

	pthread_mutex_unlock(le_philo->fork);
	pthread_mutex_unlock(le_philo->fork_right);

	writer(le_philo, "is thinking");

	return (NULL);
}

void	*monitor(void *sus)
{
	t_data	*amongus;
	t_philo	*le_philo;
	int		i;

	i = 0;
	amongus = (t_data *)sus;
	le_philo = amongus->philo;
	amongus->start_routine = get_time();
	while (le_philo->data && i < le_philo->data->nm_philo)
	{
		pthread_create(&le_philo->philo, NULL, routini, (void *)le_philo);
		pthread_join(le_philo->philo, NULL);
		le_philo = le_philo->next;
		i++;
	}
	while(1)
		;
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

	return (0);
}
