/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 08:55:01 by moel-hib          #+#    #+#             */
/*   Updated: 2025/07/13 02:11:51 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_data(t_data *data, char **av)
{
	memset(data, 0, sizeof(t_data));
	data->number_of_philo = ft_atoi(av[0]);
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
	ptr = malloc(sizeof(t_data));
	if (!ptr)
		return (NULL);
	philo = ptr;
	while (i < data->number_of_philo)
	{
		tmp = malloc(sizeof(t_data));
		if (tmp)
			return (NULL);
		ptr = ptr->next;
		ptr = tmp;
		i++;
	}
	return (philo);
}

void	fork_lock(t_data *data, t_philo *philo)
{
	int		i;
	t_philo	*tmp;
	pthread_mutex_t	*pen;

	i = 0;
	tmp = philo;
	pen = NULL;
	pthread_mutex_init(pen, NULL);
	while (i < data->number_of_philo)
	{
		tmp->last_meal = 0;
		tmp->many_eat = 0;
		tmp->time_to_eat = data->tm_eat;
		tmp->time_to_sleep = data->tm_sleep;
		pthread_mutex_init(tmp->time_to_die, NULL);
		pthread_mutex_init(tmp->tm_eat, NULL);
		pthread_mutex_init(tmp->fork, NULL);
		tmp->pen = pen;
		if (i != (data->number_of_philo - 1))
		{
			pthread_mutex_init(tmp->next->fork, NULL);
			tmp->fork_right = tmp->next->fork;
			tmp = tmp->next;
		}
		else
			tmp->fork_right = philo->fork;

		i++;
	}
}

void	*routini(void *tmp)
{
	t_philo	*le_philo;

	le_philo = (t_philo *)tmp;
	le_philo->start_routine = get_time();

	return (NULL);
}

void	*olderbrother(void *sus)
{
	t_data	*amongus = (t_data *)sus;
	t_philo *tmp = amongus->philo;

	while (tmp->next)
	{
		pthread_create(&tmp->philo, NULL, routini, (void *)tmp);
		tmp = tmp->next;
	}
	while(1)
		;
	return NULL;
}

int main(int ac, char **av)
{
	t_data	data;
	t_philo	*head;

	if (!(ac == 5 || ac == 6))
	{
		write(2, IN_ERROR, ft_strlen(IN_ERROR));
		exit(1);
	}

	init_data(&data, ++av);
	head = init_philo(&data);

	data.philo = head;

	pthread_t	t1;

	pthread_create(&t1, NULL, olderbrother, (void *)&data);

	pthread_join(t1, NULL);

	return (0);
}
