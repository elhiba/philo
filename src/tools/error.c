/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 02:52:28 by moel-hib          #+#    #+#             */
/*   Updated: 2025/08/07 01:53:50 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	errors_free(t_data *data)
{
	int		i;
	t_philo	*ptr;

	i = 0;
	if (!data)
		return ;
	if (data->philo->pen)
		free(data->philo->pen);
	while (i < data->nm_philo)
	{
		if (data->philo->fork)
			free(data->philo->fork);
		if (data->philo)
			free(data->philo);
		data->philo = NULL;
		data->philo = ptr;
		if (i != (data->nm_philo - 1))
			ptr = ptr->next;
		i++;
	}
}

int	errors(t_data *data, char *message)
{
	if (message)
		write(2, message, ft_strlen(message));
	data->failure = 1;
	errors_free(data);
	return (2);
}
