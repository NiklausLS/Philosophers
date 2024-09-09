/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 23:48:37 by nileempo          #+#    #+#             */
/*   Updated: 2024/09/09 13:29:37 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	if (data->fork_array)
	{
		while (i < data->philo_nbr)
		{
			pthread_mutex_destroy(&data->fork_array[i].fork_mutex);
			i++;
		}
		free(data->fork_array);
	}
	free(data->philo_array);
	free(data);
}
