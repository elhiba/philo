/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 08:55:25 by moel-hib          #+#    #+#             */
/*   Updated: 2025/07/13 02:01:35 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# include <string.h>
# include <errno.h>

#define IN_ERROR "You must enter the following arguments:\n\t\
	number_of_philosophers time_to_die time_to_eat time_to_sleep\
	[number_of_times_each_philosopher_must_eat]\n"

typedef struct	s_philo
{
	int				philo_id;

	pthread_t		philo;

	pthread_mutex_t	*fork;
	pthread_mutex_t	*fork_right;

	pthread_mutex_t	*tm_eat;
	pthread_mutex_t	*time_to_die;

	long long	start_routine;

	int						many_eat;
	long long				time_to_eat;
	long long				time_to_sleep;
	long long				last_meal;


	pthread_mutex_t	*pen;

	struct s_philo	*next;
}	t_philo;

typedef struct	s_data
{
	int		number_of_philo;
	int		tm_die;
	int		tm_eat;
	int		tm_sleep;
	int		tm_each_philo_meat;


	t_philo		*philo;
} t_data;

/* Tools functions */

int	ft_strlen(char *str);
int	ft_atoi(char *num);

/* Function of time */
long long	get_time();
#endif
