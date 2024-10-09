/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 00:48:52 by nileempo          #+#    #+#             */
/*   Updated: 2024/10/09 22:16:20 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	if (data->philo_nbr == 1)
	{
		handle_single_philosopher(philo);
		return (NULL);
	}
	if (philo->philo_id % 2 == 0)
		usleep(1000);
	while (1)
	{
		pthread_mutex_lock(&data->stop_mutex);
		if (data->stop)
		{
			pthread_mutex_unlock(&data->stop_mutex);
			break ;
		}
		pthread_mutex_unlock(&data->stop_mutex);
		thinking(philo);
		pthread_mutex_lock(&data->stop_mutex);
		if (data->stop)
		{
			pthread_mutex_unlock(&data->stop_mutex);
			break ;
		}
		pthread_mutex_unlock(&data->stop_mutex);
		if (philo->philo_id % 2 == 0)
		{
			pthread_mutex_lock(&(philo->right_fork->fork_mutex));
			print_state("has taken a fork", philo->philo_id, data);
			pthread_mutex_lock(&(philo->left_fork->fork_mutex));
			print_state("has taken a fork", philo->philo_id, data);
		}
		else
		{
			pthread_mutex_lock(&(philo->left_fork->fork_mutex));
			print_state("has taken a fork", philo->philo_id, data);
			pthread_mutex_lock(&(philo->right_fork->fork_mutex));
			print_state("has taken a fork", philo->philo_id, data);
		}
		pthread_mutex_lock(&data->stop_mutex);
		if (data->stop)
		{
			pthread_mutex_unlock(&data->stop_mutex);
			pthread_mutex_unlock(&(philo->left_fork->fork_mutex));
			pthread_mutex_unlock(&(philo->right_fork->fork_mutex));
			break ;
		}
		pthread_mutex_unlock(&data->stop_mutex);
		eating(philo);
		pthread_mutex_unlock(&(philo->left_fork->fork_mutex));
		pthread_mutex_unlock(&(philo->right_fork->fork_mutex));
		pthread_mutex_lock(&data->stop_mutex);
		if (data->stop)
		{
			pthread_mutex_unlock(&data->stop_mutex);
			break ;
		}
		pthread_mutex_unlock(&data->stop_mutex);
		sleeping(philo);
	}
	return (NULL);
}

void	sleeping(t_philo *philo)
{
	print_state("is sleeping", philo->philo_id, philo->data);
	lazy_sleep(philo->data->time_to_sleep, philo->data);
}

void	thinking(t_philo *philo)
{
	print_state("is thinking", philo->philo_id, philo->data);
}

void	eating(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->meal_mutex);
	print_state("is eating", philo->philo_id, data);
	philo->meal_total += 1;
	philo->last_meal = get_timestamp();
	pthread_mutex_unlock(&data->meal_mutex);
	lazy_sleep(data->time_to_eat, data);
}

void	check_stop(t_data *data)
{
	int	i;
	int	stop;

	stop = 0;
	while (!stop)
	{
		i = 0;
		while (i < data->philo_nbr)
		{
			pthread_mutex_lock(&data->stop_mutex);
			if (data->stop)
			{
				pthread_mutex_unlock(&data->stop_mutex);
				return ;
			}
			pthread_mutex_unlock(&data->stop_mutex);
			if (check_if_dead(&data->philo_array[i]))
				return ;
			i++;
		}
		pthread_mutex_lock(&data->meal_mutex);
		if (check_meal_count(data) == 1)
		{
			pthread_mutex_lock(&data->stop_mutex);
			data->stop = 1;
			pthread_mutex_unlock(&data->stop_mutex);
			printf("All philosophers have finished eating.\n");
			pthread_mutex_unlock(&data->meal_mutex);
			return ;
		}
		pthread_mutex_unlock(&data->meal_mutex);
		usleep(1000);
	}
}

int	check_if_dead(t_philo *philo)
{
	time_t	current_time;
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->meal_mutex);
	current_time = get_timestamp();
	if ((current_time - philo->last_meal) >= data->time_to_die)
	{
		pthread_mutex_lock(&data->stop_mutex);
		if (!data->stop)
		{
			data->stop = 1;
			pthread_mutex_lock(&data->print_mutex);
			printf("%ld %d died\n",
				get_timestamp() - data->time_to_start, philo->philo_id);
			pthread_mutex_unlock(&data->print_mutex);
		}
		pthread_mutex_unlock(&data->stop_mutex);
		pthread_mutex_unlock(&data->meal_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->meal_mutex);
	return (0);
}

int	check_meal_count(t_data *data)
{
	int	i;

	i = 0;
	if (data->meal_nbr < 0)
		return (0);
	while (i < data->philo_nbr)
	{
		if (data->philo_array[i].meal_total < data->meal_nbr)
			return (0);
		i++;
	}
	return (1);
}

void	handle_single_philosopher(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	print_state("has taken a fork", philo->philo_id, data);
	lazy_sleep(data->time_to_die, data);
	print_state("died", philo->philo_id, data);
	pthread_mutex_lock(&data->stop_mutex);
	data->stop = 1;
	pthread_mutex_unlock(&data->stop_mutex);
}
