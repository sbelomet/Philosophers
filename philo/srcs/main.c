/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:13:36 by sbelomet          #+#    #+#             */
/*   Updated: 2024/01/04 14:23:25 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_base	*base;

	if (ac < 5 || ac > 6)
		ft_error("Correct usage: ./philo <number_of_philosophers> "
			"<time_to_die> <time_to_eat> <time_to_sleep> "
			"[number_of_times_each_philosopher_must_eat]");
	if (!ft_numeric_check(av))
		ft_error("Positive numbers only plz");
	base = (t_base *)malloc(sizeof(t_base));
	if (!base)
		ft_error("Malloc failure (base)");
	base->nb_philo = ft_atoi(av[1]);
	base->die_time = ft_atoi(av[2]);
	base->eat_time = ft_atoi(av[3]);
	base->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		base->nb_eat = ft_atoi(av[5]);
	if (ac == 5)
		base->nb_eat = -1;
	base->philos = NULL;
	ft_philo_init(base);
	ft_free(base);
}
