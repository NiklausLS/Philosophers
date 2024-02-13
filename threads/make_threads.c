/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:01:45 by nileempo          #+#    #+#             */
/*   Updated: 2024/02/13 15:17:18 by nileempo         ###   ########.fr       */
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

	data->fork_array = (t_fork *)malloc(data->philo_nbr * sizeof(t_fork));
	if (!data->fork_array)
	{
		write(2, "Error: forks memory allocation failed.\n", 40);
		free(data);
		return ;
	}
	i = 0;
	while (i < data->philo_nbr)
	{
		data->fork_array[i].fork_id = i + 1;
		pthread_mutex_init(&data->fork_array[i].fork_mutex, NULL);
		i++;
	}
}

/*
 * Make a philosopher
 * @param ptr to my philosopher structure
 * @param id of this new philosopher
 * @param ptr to my fork structure
 */
void	init_philo_threads(t_philo *philo, int id, t_fork *fork)
{
	philo->philo_id = id;
	philo->left_fork = &fork[id - 1];
	philo->right_fork = &fork[id - 2];
	if (pthread_create(&philo->thread, NULL, events, philo) != 0)
	{
		write(2, "ERROR: Thread creation failed\n", 31);
		return ;
	}
	printf("Philosopher %d thread id :%lu\n", philo->philo_id, (unsigned long)philo->thread);
	printf("Left fork is %d. Right fork is %d\n", philo->left_fork->fork_id, philo->right_fork->fork_id);
}

void	make_philo_array(t_data *data)
{
	int	i;

	data->philo_array = (t_philo *)malloc(data->philo_nbr * sizeof(t_philo));
	if (!data->philo_array)
	{
		free(data);
		return ;
	}
	i = 0;
	while (i < data->philo_nbr)
	{
		init_philo_threads(&data->philo_array[i], i + 1, data->fork_array);
		i++;
	}
}
