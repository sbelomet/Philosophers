/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:10:28 by sbelomet          #+#    #+#             */
/*   Updated: 2024/01/17 11:12:32 by sbelomet         ###   ########.fr       */
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

# define BASE "\033[0;39m"
# define RED "\033[1;91m"
# define GREEN "\033[1;92m"
# define BLUE "\033[1;94m"

typedef struct s_philo
{
	int				name;
	int				nb_eaten;
	int				time_last_eat;
	int				dead_time;
	int				first_fork;
	int				second_fork;
	pthread_t		tid;
	struct s_base	*base;
}					t_philo;

typedef struct s_base
{
	int				running;
	int				nb_philo;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				nb_eat;
	int				starttime;
	t_philo			**philos;
	pthread_t		watcher;
	pthread_mutex_t	base_mutex;
	pthread_mutex_t	*fork_mutex;
}					t_base;

/* Utils */
int		ft_numeric_check(char **tab);
int		ft_strlen(char *s);
int		ft_atoi(char *s);
void	ft_free(t_base base);
int		ft_gettime(void);
void	ft_sleep(int usec);
int		ft_isrunning(t_base *base);
void	ft_one_philo(t_base *base, t_philo *philo);

/* Philos Utils */
int		ft_philo_init(t_base *base);
int		ft_mutex_init(t_base *base);
int		ft_feast(t_base *base);

/* Philos Phunctions */
void	ft_philo_eat(t_base *base, t_philo *philo);
void	ft_philo_sleep(t_base *base, t_philo *philo);
void	ft_philo_think(t_base *base, t_philo *philo);

/* Threads Routines */
void	*ft_routine(void *arg);
void	*ft_watching(void *arg);

/* Watcher Utils */
int		ft_check_for_dead(t_base *base, t_philo *philo, int currenttime);

#endif