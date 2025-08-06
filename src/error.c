/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 02:52:28 by moel-hib          #+#    #+#             */
/*   Updated: 2025/08/06 10:29:14 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

void	errors(t_data *data, char *message)
{
	if (message)
		perror(message);
	data->failure = 1;
	return ;
}
