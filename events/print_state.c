/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 00:34:47 by nileempo          #+#    #+#             */
/*   Updated: 2024/10/09 22:15:38 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_state(char *state, int philo_id, t_data *data)
{
	pthread_mutex_lock(&data->stop_mutex);
	if (!data->stop)
	{
		pthread_mutex_lock(&data->print_mutex);
		printf("%ld %d %s\n",
			get_timestamp() - data->time_to_start, philo_id, state);
		pthread_mutex_unlock(&data->print_mutex);
	}
	pthread_mutex_unlock(&data->stop_mutex);
}
