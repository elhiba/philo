/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:28:50 by moel-hib          #+#    #+#             */
/*   Updated: 2025/07/15 05:25:06 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

/*
	◦ Inputes data of philosophers: ◦
	
	1- number_of_philosophers
	
	2- time_to_die
	
	3- time_to_eat
	
	4- time_to_sleep
	
	5- number_of_times_each_philosopher_must_eat
*/
typedef struct s_philo_info	t_philo_info;

/*
	1- Number of phiolosopher

	2- timestamp in ms

	3- The philo fork

	4- The next philo fork

	5- This will control the pen! to write { timestamp_in_ms X has taken a fork\n ...}
 */
typedef struct s_philo_data	t_philo_data;

struct s_philo_info
{
	int				nb_of_philo;
	int				tm_to_die;
	int				tm_to_eat;
	int				tm_to_sleep;
	int				nb_tm_to_eat;

	t_philo_data	*philo_data;
};

struct s_philo_data
{
	int				philo_id; // Number of phiolosopher

	long long		philo_start; // When phiolosopher started
	int				meal_counter; // How many time this philo eats!
	int				last_meal; // last time eated

	pthread_mutex_t	left_fork; // The philo fork
	pthread_mutex_t	right_fork; // The next philo fork

	pthread_mutex_t	pen; // This will control the pen! to write { timestamp_in_ms X has taken a fork\n ...}

	t_philo_data	*next;
};

/* Functions */
/*
	Tools:
	- ft_atoi
	- philo_parser
*/

/* Convert ascii to integer */
int			ft_atoi(char *number);

/* parse inputes to the structure */
void		philo_parser(t_philo_info *philo_info, char **args);
void		philo_linker(t_philo_data *philo_data, t_philo_info *philo_info);

/* real time */
long long	current_time();

#endif
