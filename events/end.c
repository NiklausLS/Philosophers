/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:25:53 by nileempo          #+#    #+#             */
/*   Updated: 2024/09/12 00:17:27 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//check if philo have ate enough
int	check_meal_count(t_data *data)
{
	int	i;
	int	check_meal;

	i = 0;
	check_meal = 1;
	if (data->meal_nbr <= 0)
		return (0);
	while (i < data->philo_nbr)
	{
		pthread_mutex_lock(&data->meal_mutex);
		if (data->philo_array[i].meal_total < data->meal_nbr)
		{
			check_meal = 0;
			pthread_mutex_unlock(&data->meal_mutex);
			break ;
		}
		pthread_mutex_unlock(&data->meal_mutex);
		i++;
	}
	return (check_meal);
}

int	check_if_dead(t_philo *philo)
{
	time_t	current_time;
	time_t	check_last_meal;

	pthread_mutex_lock(&philo->data->meal_mutex);
	current_time = new_timestamp(philo->data);
	check_last_meal = current_time - philo->last_meal;
	if (check_last_meal >= philo->data->time_to_die)
	{
		print_state("is dead.\n", philo->philo_id, philo->data);
		philo->data->stop = 1;
		pthread_mutex_unlock(&philo->data->meal_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->meal_mutex);
	return (0);
}

void	check_stop(t_data *data)
{
	int	i;

	while (!data->stop)
	{
		i = 0;
		while (i < data->philo_nbr)
		{
			if (check_if_dead(&data->philo_array[i]))
				return ;
			i++;
		}
		if (check_meal_count(data))
		{
			pthread_mutex_lock(&data->stop_mutex);
			data->stop = 1;
			pthread_mutex_unlock(&data->stop_mutex);
			pthread_mutex_lock(&data->print_mutex);
			printf("ALL PHILOSOPHERS ARE SATISFIED\n");
			pthread_mutex_unlock(&data->print_mutex);
			return ;
		}
		lazy_sleep(1, data);
		usleep(1000);
	}
	printf("ERROR\n");
}
