/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feast_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:19:39 by sbelomet          #+#    #+#             */
/*   Updated: 2024/01/05 14:38:36 by sbelomet         ###   ########.fr       */
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
