/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:10:28 by sbelomet          #+#    #+#             */
/*   Updated: 2024/01/05 15:24:25 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <memory.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int				name;
	pthread_t		tid;
	struct s_base	*base;
}				t_philo;

typedef struct s_base
{
	int		nb_philo;
	int		die_time;
	int		eat_time;
	int		sleep_time;
	int		nb_eat;
	t_philo	**philos;
}		t_base;

/* Utils */
int		ft_numeric_check(char **tab);
int		ft_strlen(char *s);
int		ft_atoi(char *s);
void	ft_free(t_base base);

/* Philos Phunctions */
int		ft_philo_init(t_base *base);

/* Feast Functions */
int	ft_start_feast(t_base *base);

#endif