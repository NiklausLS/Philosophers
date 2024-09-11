/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:09:35 by nileempo          #+#    #+#             */
/*   Updated: 2024/09/12 00:10:19 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_philosopher_state(t_data *data, int i)
{
	if (check_if_dead(&data->philo_array[i]))
	{
		stop(data);
		return (1);
	}
	if (eating(&data->philo_array[i]) != 0)
		return (1);
	sleeping(&data->philo_array[i]);
	thinking(&data->philo_array[i]);
	return (0);
}

int	check_meals(t_data *data)
{
	int	i;
	int	enough_eats;

	i = 0;
	enough_eats = 0;
	if (data->meal_nbr <= 0)
		return (0);
	while (i < data->philo_nbr)
	{
		pthread_mutex_lock(&data->meal_mutex);
		if (data->philo_array[i].meal_total >= data->meal_nbr
			&& data->meal_nbr > 0)
			enough_eats++;
		pthread_mutex_unlock(&data->meal_mutex);
		i++;
	}
	if (enough_eats == data->philo_nbr && data->meal_nbr > 0)
	{
		stop(data);
		return (1);
	}
	return (0);
}
