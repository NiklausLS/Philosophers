/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:25:53 by nileempo          #+#    #+#             */
/*   Updated: 2024/04/23 02:09:32 by nileempo         ###   ########.fr       */
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
		printf("All philosophers are full\n");
	return (0);
}

void	check_if_dead(t_philo *philo)
{
	time_t	current_time;

	current_time = get_timestamp();
	if ((current_time - philo->last_meal) > philo->data->time_to_eat)
	{
		print_state("is dead.\n", philo->philo_id, philo->data);
		philo->alive = 0;
	}
}
