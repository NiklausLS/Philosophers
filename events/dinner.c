/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 00:48:52 by nileempo          #+#    #+#             */
/*   Updated: 2024/02/13 15:04:42 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//to do list
//eating
//sleeping
//dying

void    *events(void *arg)
{
	t_philo	*philo;
	int i = 0;

	philo = arg;
	while (i < 5)
	{
		printf("%d has taken a fork.\n", philo->philo_id);

		//printf("%d is eating.\n", philo->philo_id);

		//printf("%d is sleeping.\n", philo->philo_id);

		//printf("%d is thinking.\n", philo->philo_id);

		//printf("%d died.\n", philo->philo_id);
		i++;
	}
	return (NULL);
}