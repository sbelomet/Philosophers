/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_phunctions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:18:31 by sbelomet          #+#    #+#             */
/*   Updated: 2024/01/17 11:12:45 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_philo_eat(t_base *base, t_philo *philo)
{
	if (pthread_mutex_lock(&base->fork_mutex[philo->first_fork]) == 0)
	{
		if (base->nb_philo < 2)
			ft_one_philo(base, philo);
		if (!ft_isrunning(base))
			return ;
		printf("%d %d has taken a fork\n",
			ft_gettime() - base->starttime, philo->name);
		if (pthread_mutex_lock(&base->fork_mutex[philo->second_fork]) == 0)
		{
			if (!ft_isrunning(base))
				return ;
			philo->time_last_eat = ft_gettime();
			printf("%d %d has taken a fork\n",
				philo->time_last_eat - base->starttime, philo->name);
			printf("%d %d is "RED"eating"BASE"\n",
				philo->time_last_eat - base->starttime, philo->name);
			philo->nb_eaten++;
			philo->dead_time = philo->time_last_eat
				- base->starttime + base->die_time;
			ft_sleep(base->eat_time * 1000);
			pthread_mutex_unlock(&base->fork_mutex[philo->second_fork]);
		}
		pthread_mutex_unlock(&base->fork_mutex[philo->first_fork]);
	}
}

void	ft_philo_sleep(t_base *base, t_philo *philo)
{
	printf("%d %d is "BLUE"sleeping"BASE"\n",
		ft_gettime() - base->starttime, philo->name);
	ft_sleep(base->sleep_time * 1000);
}

void	ft_philo_think(t_base *base, t_philo *philo)
{
	printf("%d %d is "GREEN"thinking"BASE"\n",
		ft_gettime() - base->starttime, philo->name);
	if (base->nb_philo % 2)
		ft_sleep(100);
}
