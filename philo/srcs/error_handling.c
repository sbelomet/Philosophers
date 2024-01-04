/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:43:44 by sbelomet          #+#    #+#             */
/*   Updated: 2024/01/04 14:50:59 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_error(char *message)
{
	printf("ERROR: %s\n", message);
	exit(-1);
}

void	ft_error_free(char *message, t_base *base)
{
	int	i;

	printf("ERROR: %s\n", message);
	if (base)
	{
		if (base->philos)
		{
			i = 0;
			while (base->philos[i])
			{
				free(base->philos[i]);
				i++;
			}
			free(base->philos);
		}
		free(base);
	}
	exit(-1);
}
