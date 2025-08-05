/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 08:55:25 by moel-hib          #+#    #+#             */
/*   Updated: 2025/08/05 16:26:50 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <stdatomic.h>
# include <sys/time.h>
# include <string.h>

# define IN_ERROR "\e[1;41mYou must enter the following arguments:\e[0m\n\
\t\t\t\e[1;33m- number_of_philosophers\e[0m\n\
\t\t\t\e[1;31m- time_to_die\e[0m\n\
\t\t\t\e[1;35m- time_to_eat\e[0m\n\
\t\t\t\e[1;36m- time_to_sleep\e[0m\n\
\t\t\t\e[1;3m- [number_of_times_each_philosopher_must_eat]]\e[0m\n"

# define FORK "\e[1;33mhas taken a fork\e[0m"
# define EAT "\e[1;35mis eating\e[0m"
# define SLEEP "\e[1;36mis sleeping\e[0m"
# define THINK "\e[1;32mis thinking\e[0m"
# define DIE "\e[1;31mdied\e[0m"

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

	_Atomic bool			is_fork;

	_Atomic int				many_eat;
	_Atomic long			time_to_eat;
	_Atomic long			time_to_sleep;
	_Atomic long			last_meal;

	pthread_mutex_t			*pen;

	t_data					*data;

	t_philo					*next;
};

struct s_data
{
	int						nm_philo;
	long					tm_die;
	long					tm_eat;
	long					tm_sleep;
	_Atomic long				tm_each_philo_meat;

	long				start_routine;

	_Atomic bool			start;

	_Atomic bool			dead_flag;
	_Atomic bool			emergency_stop;

	t_philo					*philo;
};

/* le_task */
int			le_special_philo(t_philo *le_philo);
int			le_fork(t_philo *le_philo);
int			le_unfork(t_philo *le_philo);
int			le_eat(t_philo *le_philo);
int			le_sleep(t_philo *le_philo);
int			le_think(t_philo *le_philo);

/* Philos functions */
void		init_data(t_data *data, char **av);
t_philo		*init_philo(t_data *data);
void		fork_lock(t_data *data, t_philo *philo);

/* Tools	 functions */
int			writer(t_philo *data, char *message);
void		cleaner(t_data *data);
void		mine_sleep(long tm_sleep, t_philo *le_philo);

/* Related with LIBFT */
int			ft_strlen(char *str);
int			ft_atoi(char *num);
void		*ft_calloc(size_t nmemb, size_t size);

/* Function of time */
long		get_time(void);
//void	mine_sleep(long tm_sleep);
#endif
