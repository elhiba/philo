/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 08:55:25 by moel-hib          #+#    #+#             */
/*   Updated: 2025/07/08 03:24:55 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

# include <string.h>
# include <errno.h>

#define IN_ERROR "You must enter the following arguments:\n\tnumber_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n"

typedef struct	s_data
{
	int	number_of_philo;
	int	tm_die;
	int	tm_eat;
	int	tm_sleep;
	int	tm_each_philo_eat;
} t_data;

typedef struct	s_philo
{
	int				philo_id;

	pthread_mutex_t	fork;

	struct s_philo	*next;
} t_philo;


int	ft_strlen(char *str);

#endif
