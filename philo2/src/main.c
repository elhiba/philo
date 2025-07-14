/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:28:44 by moel-hib          #+#    #+#             */
/*   Updated: 2025/07/13 23:29:55 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

int main(int ac, char **av)
{
	t_philo_info	t_info;
	t_philo_data	t_data;

	(void)ac;
	philo_parser(&t_info, ++av);
}
