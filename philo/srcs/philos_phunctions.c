/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_phunctions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:18:55 by sbelomet          #+#    #+#             */
/*   Updated: 2024/01/05 14:39:02 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_routine(void *arg)
{
	t_philo	*philo;
	t_base	*base;

	philo = (t_philo *)arg;
	base = philo->base;
	printf("%d is eating for %d ms\n", philo->name, base->eat_time);
	usleep(base->eat_time);
	printf("%d done eating, sleep for %d ms\n", philo->name, base->sleep_time);
	usleep(base->sleep_time);
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
		if (pthread_create(&base->philos[i]->tid, NULL,
				ft_routine, (void *)base->philos[i]))
			return (0);
		i++;
	}
	base->philos[i] = NULL;
	return (1);
}
