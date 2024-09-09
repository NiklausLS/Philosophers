/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:47:25 by nileempo          #+#    #+#             */
/*   Updated: 2024/07/10 00:31:28 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_data(t_data *data)
{
	data->philo_nbr = 0;
	data->meal_nbr = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->philo_array = NULL;
	data->time_to_start = get_timestamp();
	data->stop = 0;
	pthread_mutex_init(&data->stop_mutex, NULL);
}

void	init_philo(t_philo *philo)
{
	philo->philo_id = 0;
	philo->thread = 0;
	philo->dead = 0;
	pthread_mutex_init(&philo->meal_mutex, NULL);
	pthread_mutex_init(&philo->print_mutex, NULL);
	pthread_mutex_init(&philo->death_mutex, NULL);
}

void	init_fork(t_fork *fork)
{
	fork->fork_id = -1;
}
