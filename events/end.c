/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:25:53 by nileempo          #+#    #+#             */
/*   Updated: 2024/05/04 23:28:39 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//check if philo have ate enough
int	check_meal_count(t_data *data)
{
	int	i;
	int	check_meal;

	i = 0;
	check_meal = 0;
	while (i < data->philo_nbr)
	{
		if (data->philo_array[i].meal_total < data->meal_nbr)
		{
			check_meal = 0;
			break ;
		}
		else
			check_meal = 1;
		i++;
	}
	if (check_meal == 1)
	{
		//write (1, "All philosophers are full\n", 27);
		return (check_meal);
	}
	else
		return (check_meal);
}

void	check_if_dead(t_philo *philo)
{
	time_t	current_time;
	time_t	check_last_meal;

	current_time = new_timestamp(philo->data);
	check_last_meal = current_time - philo->last_meal;
	//printf("Check if dead : last meal = %ld\n", philo->last_meal);
	//printf("current_time = %ld\n", current_time);
	//printf("philo %d last meal = %ld\n", philo->philo_id, check_last_meal);
	//printf("time_to_die = %ld\n", philo->data->time_to_die);
	pthread_mutex_lock(&philo->death_mutex);
	//printf("TEST check if dead\n");
	if (check_last_meal - philo->data->time_to_die >= philo->data->time_to_die)
	{
		//printf("check_last_meal %ld - time_to_die = %ld = %ld\n", check_last_meal, philo->data->time_to_die, (check_last_meal - philo->data->time_to_die));
		print_state("is dead.\n", philo->philo_id, philo->data);
		philo->dead = 1;
		//free(philo->left_fork);
		//free(philo->right_fork);
		//pthread_mutex_destroy(&philo->death_mutex);
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