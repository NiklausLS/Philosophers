/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 00:48:52 by nileempo          #+#    #+#             */
/*   Updated: 2024/09/09 21:10:21 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//manage all events that appends to my philosophers
void	*philo_routine(void *arg)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)arg;
	data = philo->data;
	if (philo->philo_id % 2 == 0)
		usleep(1000);
	while (!data->stop)
	{
		if (eating(philo) != 0)
			break ;
		if (sleeping(philo) != 0)
			break ;
		if (thinking(philo) != 0)
			break ;
		if (check_if_dead(philo))
			break ;
	}
	return (NULL);
}

int	eating(t_philo *philo)
{
	pthread_mutex_lock(&(philo->left_fork->fork_mutex));
	print_state("has taken a fork\n", philo->philo_id, philo->data);
	pthread_mutex_lock(&(philo->right_fork->fork_mutex));
	print_state("has taken a fork\n", philo->philo_id, philo->data);
	print_state("is eating\n", philo->philo_id, philo->data);
	lazy_sleep(philo->data->time_to_eat, philo->data);
	philo->meal_total += 1;
	philo->last_meal = get_timestamp();
	pthread_mutex_unlock(&philo->data->meal_mutex);
	if (pthread_mutex_unlock(&(philo->left_fork->fork_mutex)) != 0)
	{
		write (2, "Error for left fork mutex unlock\n", 34);
		return (1);
	}
	if (pthread_mutex_unlock(&(philo->right_fork->fork_mutex)) != 0)
	{
		write (2, "Error for right fork mutex unlock\n", 35);
		return (1);
	}
	return (0);
}

int	sleeping(t_philo *philo)
{
	print_state("is sleeping\n", philo->philo_id, philo->data);
	lazy_sleep(philo->data->time_to_sleep, philo->data);
	return (0);
}

int	thinking(t_philo *philo)
{
	print_state("is thinking\n", philo->philo_id, philo->data);
	return (0);
}

void	stop(t_data *data)
{
	pthread_mutex_lock(&data->stop_mutex);
	data->stop = 1;
	pthread_mutex_unlock(&data->stop_mutex);
}
