/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 08:55:25 by moel-hib          #+#    #+#             */
/*   Updated: 2025/07/26 10:14:58 by moel-hib         ###   ########.fr       */
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

# define IN_ERROR "You must enter the following arguments:\n\t\
	number_of_philosophers time_to_die time_to_eat time_to_sleep\
	[number_of_times_each_philosopher_must_eat]\n"

typedef struct s_philo	t_philo;
typedef struct s_data	t_data;

/*
		1 - philo_id
		2 - philo;        
		              
		*fork;        
		*fork_right;  
		              
		*tm_eat;      
		*time_to_die; 
		              
		start_routine;
		              
		many_eat;     
		time_to_eat;  
		time_to_sleep;
		last_meal;    
		              
		*pen;         
		              
		*next;        

 */
struct s_philo
{
	int						philo_id;

	pthread_t				philo;

	pthread_mutex_t			*fork;
	pthread_mutex_t			*fork_right;

	pthread_mutex_t			*tm_eat;
	pthread_mutex_t			*time_to_die;


	int						many_eat;
	long long				time_to_eat;
	long long				time_to_sleep;
	long long				last_meal;

	pthread_mutex_t			*pen;

	t_data					*data;

	struct s_philo			*next;
};

struct s_data
{
	int						nm_philo;
	int						tm_die;
	int						tm_eat;
	int						tm_sleep;
	int						tm_each_philo_meat;

	long long				start_routine;

	t_philo					*philo;
};

/* Tools functions */
void	writer(t_philo *data, char *message);

/* Related with LIBFT */
int			ft_strlen(char *str);
int			ft_atoi(char *num);

/* Function of time */
long long	get_time(void);
#endif
