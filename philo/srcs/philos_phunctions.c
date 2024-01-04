/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_phunctions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:18:55 by sbelomet          #+#    #+#             */
/*   Updated: 2024/01/04 14:51:59 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_routine(void *arg)
{
	t_base	*base;

	base = (t_base *)arg;
	printf("i die in %d ms\n", base->die_time);
	return (NULL);
}

void	ft_philo_init(t_base *base)
{
	int		i;

	base->philos = (t_philo **)malloc(base->nb_philo * sizeof(t_philo *));
	if (!base->philos)
		ft_error_free("Malloc failure (philos)", base);
	i = 0;
	while (i < base->nb_philo)
	{
		base->philos[i] = (t_philo *)malloc(sizeof(t_philo));
		if (!base->philos[i])
			ft_error_free("Malloc failure (philos)", base);
		if (pthread_create(&base->philos[i]->tid, NULL,
				ft_routine, (void *)base))
			ft_error_free("Thread creation failure", base);
		i++;
	}
	i = 0;
	while (i < base->nb_philo)
	{
		if (pthread_join(base->philos[i]->tid, NULL))
			ft_error_free("Thread joining failure", base);
		i++;
	}
}
