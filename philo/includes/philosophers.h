/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:10:28 by sbelomet          #+#    #+#             */
/*   Updated: 2024/01/04 14:50:50 by sbelomet         ###   ########.fr       */
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
	int			name;
	pthread_t	tid;
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

/* Error Handling */
void	ft_error(char *message);
void	ft_error_free(char *message, t_base *base);

/* Utils */
int		ft_numeric_check(char **tab);
int		ft_strlen(char *s);
int		ft_atoi(char *s);
void	ft_free(t_base *base);

/* Philos Phunctions */
void	ft_philo_init(t_base *base);

#endif