/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_routines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:51:47 by sbelomet          #+#    #+#             */
/*   Updated: 2024/01/17 10:31:12 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_routine(void *arg)
{
	t_philo	*philo;
	t_base	*base;

	philo = (t_philo *)arg;
	base = philo->base;
	while (!base->running)
	{
	}
	if (philo->name % 2)
		ft_sleep(100);
	if (base->nb_eat == 0)
		return (NULL);
	while (ft_isrunning(base))
	{
		if (ft_isrunning(base))
			ft_philo_eat(base, philo);
		if (base->nb_eat != -1 && base->nb_eat == philo->nb_eaten)
			break ;
		if (ft_isrunning(base))
			ft_philo_sleep(base, philo);
		if (ft_isrunning(base))
			ft_philo_think(base, philo);
	}
	return (NULL);
}

void	*ft_watching(void *arg)
{
	t_base	*base;
	int		i;
	int		currenttime;

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
			if (!ft_check_for_dead(base, base->philos[i], currenttime))
				break ;
			i++;
		}
	}
	return (NULL);
}
