/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_routines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:51:47 by sbelomet          #+#    #+#             */
/*   Updated: 2024/01/11 13:59:07 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_routine(void *arg)
{
	t_philo	*philo;
	t_base	*base;

	philo = (t_philo *)arg;
	base = philo->base;
	base->starttime = ft_gettime();
	while (!base->running)
	{
	}
	while (base->running)
	{
		if (philo->nb_eaten != -1 && philo->nb_eaten == base->nb_eat)
		{
			base->running = 0;
			break ;
		}
		ft_philo_eat(base, philo);
		ft_philo_sleep(base, philo);
		ft_philo_think(base, philo);
		philo->nb_eaten++;
	}
	return (NULL);
}

void	*ft_watching(void *arg)
{
	t_base	*base;
	int		i;
	int		currenttime;
	int		done_eating; // TODO

	base = (t_base *)arg;
	while (!base->running)
	{
	}
	while (base->running)
	{
		i = 0;
		currenttime = ft_gettime();
		while (base->philos[i])
		{
			ft_check_for_dead(base, base->philos[i], currenttime);
			i++;
		}
	}
	return (NULL);
}