/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 21:04:55 by moel-hib          #+#    #+#             */
/*   Updated: 2025/07/13 21:56:51 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/philo.h"

void	philo_parser(t_philo_info *philo_info, char **args)
{
	memset(philo_info, 0, sizeof(t_philo_info));
	philo_info->nb_of_philo = ft_atoi(args[0]);
	philo_info->tm_to_die = ft_atoi(args[1]);
	philo_info->nb_tm_to_eat = ft_atoi(args[2]);
	philo_info->tm_to_sleep = ft_atoi(args[3]);
	if (args[4])
		philo_info->nb_tm_to_eat = ft_atoi(args[4]);
}
