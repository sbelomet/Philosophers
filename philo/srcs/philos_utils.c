/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:18:55 by sbelomet          #+#    #+#             */
/*   Updated: 2024/01/10 15:39:17 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_feast(t_base *base)
{
	int	i;

	base->running = 1;
	i = 0;
	while (i < base->nb_philo)
	{
		if (pthread_join(base->philos[i]->tid, NULL))
			return (0);
		i++;
	}
	if (pthread_join(base->watcher, NULL))
		return (0);
	return (1);
}

int	ft_individual_philo_init(t_base *base)
{
	int	i;

	i = 0;
	while (i < base->nb_philo)
	{
		base->philos[i] = (t_philo *)malloc(sizeof(t_philo));
		if (!base->philos[i])
			return (0);
		base->philos[i]->base = base;
		base->philos[i]->name = i + 1;
		base->philos[i]->nb_eaten = 0;
		base->philos[i]->first_fork = i;
		base->philos[i]->second_fork = (i + 1) % base->nb_philo;
		if (base->philos[i]->name % 2)
		{
			base->philos[i]->first_fork = (i + 1) % base->nb_philo;
			base->philos[i]->second_fork = i;
		}
		if (pthread_create(&base->philos[i]->tid, NULL,
				ft_routine, (void *)base->philos[i]))
			return (0);
		i++;
	}
	base->philos[i] = NULL;
	return (1);
}

int	ft_mutex_init(t_base *base)
{
	int	i;

	i = 0;
	base->fork_mutex = (pthread_mutex_t *)malloc(base->nb_philo
			* sizeof(pthread_mutex_t));
	if (!base->fork_mutex)
		return (0);
	while (i < base->nb_philo)
	{
		pthread_mutex_init(&base->fork_mutex[i], NULL);
		i++;
	}
	return (1);
}

int	ft_philo_init(t_base *base)
{
	base->philos = (t_philo **)malloc((base->nb_philo + 1) * sizeof(t_philo *));
	if (!base->philos)
		return (0);
	if (!ft_individual_philo_init(base))
		return (0);
	if (pthread_create(&base->watcher, NULL, ft_watching, (void *)base))
		return (0);
	if (!ft_mutex_init(base))
		return (0);
	return (1);
}
