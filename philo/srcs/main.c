/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:13:36 by sbelomet          #+#    #+#             */
/*   Updated: 2024/01/05 15:31:00 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_base_init(t_base *base, int ac, char **av)
{
	base->nb_philo = ft_atoi(av[1]);
	base->die_time = ft_atoi(av[2]);
	base->eat_time = ft_atoi(av[3]);
	base->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		base->nb_eat = ft_atoi(av[5]);
	if (ac == 5)
		base->nb_eat = -1;
	base->philos = NULL;
	if (!ft_philo_init(base))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_base	base;

	if (ac < 5 || ac > 6)
	{
		printf("Correct usage: ./philo <number_of_philosophers> "
			"<time_to_die> <time_to_eat> <time_to_sleep> "
			"[number_of_times_each_philosopher_must_eat]\n");
		return (-1);
	}
	if (!ft_numeric_check(av))
	{
		printf("Positive numbers only plz\n");
		return (-1);
	}
	if (ft_base_init(&base, ac, av))
		ft_start_feast(&base);
	ft_free(base);
}
