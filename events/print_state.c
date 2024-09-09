/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 00:34:47 by nileempo          #+#    #+#             */
/*   Updated: 2024/09/09 21:12:47 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_state(char *state, int philo_id, t_data *data)
{
	pthread_mutex_lock(&data->print_mutex);
	if (!data->stop)
		printf("%ld %d %s", new_timestamp(data), philo_id, state);
	pthread_mutex_unlock(&data->print_mutex);
}
