/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:11:29 by sbelomet          #+#    #+#             */
/*   Updated: 2024/01/16 11:49:31 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

int	ft_numeric_check(char **tab)
{
	int	i;
	int	j;

	i = 1;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j] == '+' || (tab[i][j] >= '0' && tab[i][j] <= '9'))
		{	
			if ((tab[i][j] == '+')
				&& !(tab[i][j + 1] >= '0' && tab[i][j + 1] <= '9'))
				return (0);
			j++;
		}
		if (j != ft_strlen(tab[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(char *s)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res);
}

void	ft_free(t_base base)
{
	int	i;

	if (base.philos)
	{
		i = 0;
		while (base.philos[i])
		{
			free(base.philos[i]);
			i++;
		}
		free(base.philos);
	}
	if (base.fork_mutex)
	{
		i = 0;
		while (i < base.nb_philo)
		{
			pthread_mutex_destroy(&base.fork_mutex[i]);
			i++;
		}
		free(base.fork_mutex);
	}
	pthread_mutex_destroy(&base.base_mutex);
}

int	ft_gettime(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}
