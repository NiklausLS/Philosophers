/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:25:53 by nileempo          #+#    #+#             */
/*   Updated: 2024/04/23 13:57:05 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//check if philo have ate enough
int	check_meal_count(t_data *data)
{
	int	i;
	int	meal_ok;

	i = 0;
	meal_ok = 1;
	while (i < data->philo_nbr)
	{
		if (data->philo_array[i].meal_total < data->meal_nbr)
		{
			meal_ok = 0;
			return (1);
		}
		i++;
	}
	if (meal_ok == 1)
		write (1, "All philosophers are full\n", 27);
	return (0);
}

void	check_if_dead(t_philo *philo)
{
	time_t	current_time;

	current_time = get_timestamp();
	pthread_mutex_lock(&philo->philo_mutex);
	//printf("TEST check if dead\n");
	if ((current_time - philo->last_meal) > philo->data->time_to_eat)
	{
		print_state("is dead.\n", philo->philo_id, philo->data);
		philo->alive = 0;
		free(philo->left_fork);
		free(philo->right_fork);
		pthread_mutex_destroy(&philo->philo_mutex);
	}
	pthread_mutex_unlock(&philo->philo_mutex);
}

void	*check_dinner(void *arg)
{
	t_data *data;

	data = (t_data *)arg;
	while (1)
	{
		check_meal_count(data);
		usleep(10);
	}
	return (NULL);
}