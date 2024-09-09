/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 23:48:37 by nileempo          #+#    #+#             */
/*   Updated: 2024/07/09 23:54:05 by nileempo         ###   ########.fr       */
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
	i = 0;
	if (data->philo_array)
	{
		while (i < data->philo_nbr)
		{
			pthread_mutex_destroy(&data->philo_array[i].meal_mutex);
			pthread_mutex_destroy(&data->philo_array[i].print_mutex);
			pthread_mutex_destroy(&data->philo_array[i].death_mutex);
		}
		free(data->philo_array);
	}
	free(data);
}
