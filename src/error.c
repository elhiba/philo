/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 02:52:28 by moel-hib          #+#    #+#             */
/*   Updated: 2025/08/06 14:40:45 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

void	errors_free()
{
}

void	errors(t_data *data, char *message)
{
	if (message)
		write(2, message, ft_strlen(message));
	data->failure = 1;
	return ;
}
