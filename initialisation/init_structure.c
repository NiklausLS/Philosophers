/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:47:25 by nileempo          #+#    #+#             */
/*   Updated: 2024/02/13 15:18:53 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_struct(t_data *data)
{
	data->philo_nbr = 0;
	data->eat_nbr = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->philo_array = NULL;
}

void	init_philo(t_philo *philo)
{
	philo->philo_id = 0;
	philo->thread = 0;
}

void	init_fork(t_fork *fork)
{
	fork->fork_id = 0;
}
