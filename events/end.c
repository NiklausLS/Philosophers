/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:25:53 by nileempo          #+#    #+#             */
/*   Updated: 2024/05/01 20:58:25 by nileempo         ###   ########.fr       */
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
	pthread_mutex_lock(&philo->death_mutex);
	//printf("TEST check if dead\n");
	if ((current_time - philo->last_meal) > philo->data->time_to_eat)
	{
		print_state("is dead.\n", philo->philo_id, philo->data);
		philo->dead = 1;
		//free(philo->left_fork);
		//free(philo->right_fork);
		pthread_mutex_destroy(&philo->death_mutex);
	}
	pthread_mutex_unlock(&philo->death_mutex);
}

/*
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
}*/