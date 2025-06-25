/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 08:55:01 by moel-hib          #+#    #+#             */
/*   Updated: 2025/06/25 09:22:31 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <pthread.h>

void	error(char *msg)
{
	write(2, msg, strlen(msg));
	strerror(errno);
	exit(-1);
}

void	*do_it()
{
	int	i;

	i = 0;
	while (i < 5)
	{
		sleep(1);
		write(1, "do_it\n", strlen("do_it\n"));
		i++;
	}
	return (NULL);
}

void	*do_not()
{
	int	i;

	i = 0;
	while (i < 5)
	{
		sleep(1);
		write(1, "do_not\n", strlen("do_not\n"));
		i++;
	}
	return (NULL);
}

int main()
{
	void	*result;
	pthread_t	t0;
	pthread_t	t1;

	if (pthread_create(&t0, NULL, do_it, NULL) == -1)
		error("We cam't create a thread on t0");
	if (pthread_create(&t1, NULL, do_not, NULL) == -1)
		error("We cam't create a thread on t1");

	if(pthread_join(t0, &result) == -1)
		error("Can't join thread t0");
	if(pthread_join(t1, &result) == -1)
		error("Can't join thread t1");

	return (0);
}
