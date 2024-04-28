/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:01:45 by nileempo          #+#    #+#             */
/*   Updated: 2024/04/23 13:40:37 by nileempo         ###   ########.fr       */
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
		free(data);
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
	int	i;
	t_philo	*philo;

	i = 0;
	while (i < data->philo_nbr)
	{
		philo = &data->philo_array[i];
		philo->left_fork = &data->fork_array[i + (data->philo_array->philo_id - 1)];
		philo->right_fork = &data->fork_array[i + 1 % (data->philo_array->philo_id - 1)];
		philo->meal_total = 0;
		usleep(1000);
		if (pthread_create(&philo->thread, NULL, events, philo) != 0)
		{
			write(2, "ERROR: Thread creation failed\n", 31);
			return ;
		}
		//printf("Philosopher %d thread id : %lu\n", philo->philo_id, (unsigned long)philo->thread);
		//printf("Left fork is %d. Right fork is %d\n", philo->left_fork->fork_id, philo->right_fork->fork_id);
		//printf("Philo %d have to eat %d times\n", philo->philo_id, philo->data->meal_nbr);
		i++;
	}
	i = 0;
	/*while (i < data->philo_nbr)
	{
		usleep(100);
		if (pthread_join(data->philo_array[i].thread, NULL))
			return ;
		i++;
	}*/
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
		data->philo_array[i].last_meal = get_timestamp();
		data->philo_array[i].philo_id = i + 1;
		data->philo_array[i].data = data;
		data->philo_array[i].alive = 1;
		i++;
	}
}
