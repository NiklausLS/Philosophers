/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tempus_fugit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:47:14 by nileempo          #+#    #+#             */
/*   Updated: 2024/10/09 22:16:41 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

time_t	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	lazy_sleep(long time, t_data *data)
{
	time_t	start;

	start = get_timestamp();
	while (1)
	{
		pthread_mutex_lock(&data->stop_mutex);
		if (data->stop)
		{
			pthread_mutex_unlock(&data->stop_mutex);
			break ;
		}
		pthread_mutex_unlock(&data->stop_mutex);
		if (get_timestamp() - start >= time)
			break ;
		usleep(100);
	}
}
