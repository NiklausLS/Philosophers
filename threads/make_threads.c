/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:01:45 by nileempo          #+#    #+#             */
/*   Updated: 2024/09/09 21:06:32 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
 * Make a fork for each philosopher
 * @param ptr to my data structure
 */
void	make_forks_array(t_data *data)
{
	int	i;

	i = 0;
	data->fork_array = (t_fork *)malloc(data->philo_nbr * sizeof(t_fork));
	if (!data->fork_array)
	{
		write(2, "Error: forks memory allocation failed.\n", 40);
		return ;
	}
	while (i < data->philo_nbr)
	{
		data->fork_array[i].fork_id = i + 1;
		if (pthread_mutex_init(&data->fork_array[i].fork_mutex, NULL) != 0)
		{
			write (2, "Error: forks mutex initialisation failed\n", 42);
		}
		i++;
	}
}

/*
 * Make a thread for each philosopher
 * @param ptr to my data structure
*/
void	make_philo_threads(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < data->philo_nbr)
	{
		philo = &data->philo_array[i];
		philo->left_fork = &data->fork_array[i];
		philo->right_fork = &data->fork_array[(i + 1) % (data->philo_nbr)];
		philo->meal_total = 0;
		if (pthread_create(&philo->thread, NULL, philo_routine, philo) != 0)
		{
			write(2, "ERROR: Thread creation failed\n", 31);
			free_data(data);
			return ;
		}
		i++;
	}
}

/*
 * Make an array of philosophers and init their data
 * @param ptr to my data structure
*/
void	make_philo_array(t_data *data)
{
	int	i;

	i = 0;
	data->philo_array = (t_philo *)malloc(data->philo_nbr * sizeof(t_philo));
	if (!data->philo_array)
	{
		write (2, "ERROR: Philosopher array creation failed\n", 42);
		return ;
	}
	while (i < data->philo_nbr)
	{
		data->philo_array[i].meal_total = 0;
		data->philo_array[i].last_meal = new_timestamp(data);
		data->philo_array[i].philo_id = i + 1;
		data->philo_array[i].data = data;
		i++;
	}
}
