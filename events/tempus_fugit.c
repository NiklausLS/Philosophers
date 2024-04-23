/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tempus_fugit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:47:14 by nileempo          #+#    #+#             */
/*   Updated: 2024/04/23 02:10:54 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/philo.h>

//to do list
//recup timestamp
//calculer différence timestamp

/*void	*dinner_time(void *data)
{
    
}*/

/*
 * Get the time in milliseconds and returns it
 */
time_t	get_timestamp(void)
{
	struct timeval		tv;
	time_t				timestamp;

	gettimeofday(&tv, NULL);
	timestamp = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (timestamp);
}

time_t	new_timestamp(t_data *data)
{
	struct timeval	tv;
	time_t			new;

	gettimeofday(&tv, NULL);
	new = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	new = (new - data->time_to_start);
	return (new);
}
