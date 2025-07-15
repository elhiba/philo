/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:28:44 by moel-hib          #+#    #+#             */
/*   Updated: 2025/07/15 05:26:42 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

//void	*monitoring(void *philo_data)
//{
//
//	return (NULL);
//}

int	main(int ac, char **av)
{
	t_philo_info	t_info;
	t_philo_data	t_data;
//	pthread_t		monitor;

	(void)ac;
	philo_parser(&t_info, ++av);
	philo_linker(&t_data, &t_info);

	printf("%i %i", t_data.next->philo_id, t_data.meal_counter);


//	pthread_create(&monitor, NULL, monitoring, NULL);
}
