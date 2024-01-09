/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:18:55 by sbelomet          #+#    #+#             */
/*   Updated: 2024/01/09 14:17:30 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_start_feast(t_base *base)
{
	int	i;

	i = 0;
	while (i < base->nb_philo)
	{
		if (pthread_join(base->philos[i]->tid, NULL))
			return (0);
		i++;
	}
	return (1);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;
	t_base	*base;

	philo = (t_philo *)arg;
	base = philo->base;
	base->starttime = ft_gettime();
	while (1)
	{
		if (philo->nb_eaten != -1 && philo->nb_eaten == base->nb_eat)
			break ;
		ft_philo_eat(base, philo);
		ft_philo_sleep(base, philo);
		ft_philo_think(base, philo);
		philo->nb_eaten++;
	}
	return (NULL);
}

int	ft_philo_init(t_base *base)
{
	int		i;

	base->philos = (t_philo **)malloc((base->nb_philo + 1) * sizeof(t_philo *));
	if (!base->philos)
		return (0);
	i = 0;
	while (i < base->nb_philo)
	{
		base->philos[i] = (t_philo *)malloc(sizeof(t_philo));
		if (!base->philos[i])
			return (0);
		base->philos[i]->base = base;
		base->philos[i]->name = i + 1;
		base->philos[i]->nb_eaten = 0;
		base->philos[i]->left_fork = (i + 1) % base->nb_philo;
		base->philos[i]->right_fork = i;
		if (pthread_create(&base->philos[i]->tid, NULL,
				ft_routine, (void *)base->philos[i]))
			return (0);
		i++;
	}
	base->philos[i] = NULL;
	pthread_mutex_init(&base->mutex, NULL);
	return (1);
}
