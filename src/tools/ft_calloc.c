/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 15:44:41 by moel-hib          #+#    #+#             */
/*   Updated: 2025/07/27 15:50:51 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*addr;

	if (size <= 0)
		return (NULL);
	addr = malloc(size * nmemb);
	if (!addr)
		return (NULL);
	memset(addr, 0, sizeof(size));
	return (addr);
}
