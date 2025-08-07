/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   le_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 01:46:43 by moel-hib          #+#    #+#             */
/*   Updated: 2025/08/07 01:46:58 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

// TODO: le_special_philo should always be special!
int	le_special_philo(t_philo *le_philo)
{
	if (le_philo->data->nm_philo == 1)
	{
		pthread_mutex_lock(le_philo->fork);
		writer(le_philo, FORK);
		pthread_mutex_unlock(le_philo->fork);
		return (1);
	}
	return (0);
}
