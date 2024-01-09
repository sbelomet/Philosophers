/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_phunctions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:18:31 by sbelomet          #+#    #+#             */
/*   Updated: 2024/01/09 15:08:55 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_philo_eat(t_base *base, t_philo *philo)
{
	philo->time_last_eat = ft_gettime();
	printf("%d: %d is "RED"eating"BASE"\n",
		philo->time_last_eat - base->starttime, philo->name);
	ft_sleep(base->eat_time * 1000);
}

void	ft_philo_sleep(t_base *base, t_philo *philo)
{
	printf("%d: %d is "GREEN"sleeping"BASE"\n",
		ft_gettime() - base->starttime, philo->name);
	ft_sleep(base->sleep_time * 1000);
}

void	ft_philo_think(t_base *base, t_philo *philo)
{
	int	currenttime;

	currenttime = ft_gettime();
	printf("%d: %d is "BLUE"thinking"BASE"\n",
		currenttime - base->starttime, philo->name);
	ft_sleep((base->die_time - (currenttime - philo->time_last_eat)) * 1000);
}
