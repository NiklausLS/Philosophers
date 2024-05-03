/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tempus_fugit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:47:14 by nileempo          #+#    #+#             */
/*   Updated: 2024/05/02 19:20:53 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/philo.h>

//to do list
//recup timestamp
//calculer différence timestamp

/*
 * Get the time in milliseconds and returns it
 */
time_t	get_timestamp(void)
{
	struct timeval		tv;
	time_t				timestamp;

	if (gettimeofday(&tv, NULL) == -1)
	{
		write (2, "get_timestamp had an issue\n", 28);
		return (-1);
	}
	timestamp = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (timestamp);
}

time_t	new_timestamp(t_data *data)
{
	struct timeval	tv;
	time_t			new;

	if (gettimeofday(&tv, NULL) == -1)
	{
		write (2, "get_timestamp had an issue\n", 28);
		return (-1);
	}
	new = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	new = (new - data->time_to_start);
	return (new);
}

time_t	death_timestamp(t_philo *philo)
{
	struct timeval tv;
	time_t			death_time;

	if(gettimeofday(&tv, NULL) == -1)
	{
		write (2, "death_timestamp had an issue\n", 30);
		return (-1);
	}
	death_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	printf("death_timestamp : philo->last_meal = %ld\n", philo->last_meal);
	death_time = (death_time - philo->last_meal);
	return (death_time);
}
