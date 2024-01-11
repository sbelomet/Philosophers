/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:52:13 by sbelomet          #+#    #+#             */
/*   Updated: 2024/01/11 13:59:14 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_check_eaten_meals(t_base *base, t_philo *philo, int currenttime)
{
	// TODO
}

int	ft_check_for_dead(t_base *base, t_philo *philo, int currenttime)
{
	if (base->die_time < currenttime - philo->time_last_eat)
	{
		base->running = 0;
		printf("%d %d has died\n",
			currenttime - base->starttime, philo->name);
		return (0);
	}
	return (1);
}
