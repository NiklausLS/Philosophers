/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 00:34:47 by nileempo          #+#    #+#             */
/*   Updated: 2024/04/23 13:04:11 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_state(char *state, int philo_id, t_data *data)
{
	time_t	timestamp;

	timestamp = new_timestamp(data);
	if (pthread_mutex_lock(&data->philo_array[philo_id].print_mutex))
	{
		printf("%ld %d %s", timestamp, philo_id, state);
		pthread_mutex_unlock(&data->philo_array[philo_id].print_mutex);
	}
	else
	{
		printf("Error with mutex lock\n");
		return ;
	}
}
