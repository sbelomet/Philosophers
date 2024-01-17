/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:52:13 by sbelomet          #+#    #+#             */
/*   Updated: 2024/01/17 10:29:56 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_check_for_dead(t_base *base, t_philo *philo, int currenttime)
{
	if (philo->dead_time < currenttime - base->starttime)
	{
		pthread_mutex_lock(&base->base_mutex);
		base->running = 0;
		printf("%d %d died\n",
			currenttime - base->starttime, philo->name);
		pthread_mutex_unlock(&base->base_mutex);
		return (0);
	}
	return (1);
}
