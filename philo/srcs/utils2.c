/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:20:54 by sbelomet          #+#    #+#             */
/*   Updated: 2024/01/16 11:55:05 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_sleep(int usec)
{
	struct timeval	starttime;
	struct timeval	currenttime;
	int				elapsedtime;
	int				remaining;

	gettimeofday(&starttime, NULL);
	elapsedtime = 0;
	while (elapsedtime < usec)
	{
		remaining = usec - elapsedtime;
		if (remaining > 1000)
			usleep(remaining / 2);
		gettimeofday(&currenttime, NULL);
		elapsedtime = (currenttime.tv_sec - starttime.tv_sec) * 1000000
			+ (currenttime.tv_usec - starttime.tv_usec);
	}
}

int	ft_isrunning(t_base *base)
{
	pthread_mutex_lock(&base->base_mutex);
	if (base->running)
	{
		pthread_mutex_unlock(&base->base_mutex);
		return (1);
	}
	pthread_mutex_unlock(&base->base_mutex);
	return (0);
}
