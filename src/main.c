/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 08:55:01 by moel-hib          #+#    #+#             */
/*   Updated: 2025/07/27 15:55:01 by moel-hib         ###   ########.fr       */
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
	ptr = malloc(sizeof(t_philo));
	if (!ptr)
		return (NULL);
	memset(ptr, 0, sizeof(t_philo));
	philo = ptr;
	while (i < data->nm_philo)
	{
		tmp = malloc(sizeof(t_philo));
		if (!tmp)
			return (NULL);
		memset(tmp, 0, sizeof(t_philo));
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
	while (i < data->nm_philo)
	{
		ptr->philo_id = i + 1;
		ptr->time_to_eat = data->tm_eat;
		ptr->time_to_sleep = data->tm_sleep;
		ptr->pen = pen;
		ptr->data = data;
		ptr->time_to_die = ft_calloc(1, sizeof(pthread_mutex_t));
		ptr->tm_eat = ft_calloc(1, sizeof(pthread_mutex_t));
		ptr->fork = ft_calloc(1, sizeof(pthread_mutex_t));
		pthread_mutex_init(ptr->time_to_die, NULL);
		pthread_mutex_init(ptr->tm_eat, NULL);
		pthread_mutex_init(ptr->fork, NULL);
		ptr = ptr->next;
		i++;
	}
	philo_linker(philo);
}

void	*routini(void *tmp)
{
	t_philo		*le_philo;
	_Atomic int	i;

	i = 0;
	le_philo = (t_philo *)tmp;
	if (le_philo->philo_id % 2 == 0)
		usleep(20000);
	while (1 && !le_philo->data->dead_flag)
	{
		if (le_philo->data->tm_each_philo_meat != -1)
		{
			if (le_philo->data->tm_each_philo_meat == i)
				break ;
		}

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

		pthread_mutex_lock(le_philo->time_to_die);
		le_philo->last_meal = get_time();
		pthread_mutex_unlock(le_philo->time_to_die);

		writer(le_philo, "is eating");
		usleep(le_philo->data->tm_eat * 1000LL);

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
		usleep(le_philo->data->tm_sleep * 1000LL);

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
		le_philo = le_philo->next;
		i++;
	}

	i = 0;
	while(1)
	{
		if (le_philo->data->tm_each_philo_meat == i)
			break ;
		pthread_mutex_lock(le_philo->time_to_die);
		if (le_philo->data->tm_die <= (get_time() - le_philo->last_meal))
		{
			writer(le_philo, "died");
			le_philo->data->dead_flag = 1;
			pthread_mutex_unlock(le_philo->time_to_die);
			break ;
		}
		pthread_mutex_unlock(le_philo->time_to_die);
		++i;
		usleep(1000);
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
