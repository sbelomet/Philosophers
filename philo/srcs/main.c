/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:13:36 by sbelomet          #+#    #+#             */
/*   Updated: 2024/01/02 15:29:21 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_philo_init(int die_time, int eat_time, int sleep_time, int nb_eat)
{
	static int	i = 1;

	printf("Philo %d with %d, %d, %d, %d\n", i++, die_time, eat_time, sleep_time, nb_eat);
}

int	main(int ac, char **av)
{
	int	i;
	int	nb_eat;
	char *s = (char *)malloc(10);

	s[3] = '4';
	if (ac < 5 || ac > 6)
		ft_error("Correct usage: ./philo <number_of_philosophers> "
			"<time_to_die> <time_to_eat> <time_to_sleep> "
			"[number_of_times_each_philosopher_must_eat]");
	if (!ft_numeric_check(av))
		ft_error("Positive numbers only plz");
	if (ac == 6)
		nb_eat = ft_atoi(av[5]);
	if (ac == 5)
		nb_eat = -1;
	i = 0;
	while (i++ < ft_atoi(av[1]))
		ft_philo_init(ft_atoi(av[2]), ft_atoi(av[3]), ft_atoi(av[4]), nb_eat);
}
