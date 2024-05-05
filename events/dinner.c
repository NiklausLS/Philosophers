/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 00:48:52 by nileempo          #+#    #+#             */
/*   Updated: 2024/05/05 05:54:21 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	eating(t_philo *philo);
static int	thinking(t_philo *philo);
static int	sleeping(t_philo *philo);

//manage all events that appends to my philosophers
void	*events(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo == NULL)
	{
		printf("Error : arg is invalid\n");
		return (NULL);
	}
	if (philo->philo_id % 2 == 0)
		usleep(10);
	while (1)
	{	
		if (philo->dead == 1)
			break ;
		if (check_meal_count(philo->data) == 1)
			break ;
		check_if_dead(philo);
		//printf("meal_timestamp = %ld\n", philo->last_meal);
		if (philo->dead == 1)
			break ;
		if (eating(philo) == 0)
		{
			if (check_meal_count(philo->data) == 1)
				break ;
			//check_if_dead(philo);
			if (philo->dead == 1)
				break ;
			sleeping(philo);
			//check_if_dead(philo);
			if (philo->dead == 1)
				break ;
		}
		else if (eating(philo) == 1)
			break ;
		thinking(philo);
		check_if_dead(philo);
	}
	return (arg);
}

static int	eating(t_philo *philo)
{
	if (pthread_mutex_lock(&(philo->left_fork->fork_mutex)) != 0)
	{
		write (2, "Error with left mutex lock\n", 28);
		return (1);
	}
	//printf("%d has taken the fork on his left [%d].\n", philo->philo_id, philo->left_fork->fork_id);
	print_state("has taken a fork\n", philo->philo_id, philo->data);
	if (pthread_mutex_lock(&(philo->right_fork->fork_mutex)) != 0)
	{
		write (2, "Error with right mutex lock\n", 29);
		return (1);
	}
	//printf("%d has taken the fork on his right [%d].\n", philo->philo_id, philo->right_fork->fork_id);
	print_state("has taken a fork\n", philo->philo_id, philo->data);
	print_state("is eating\n", philo->philo_id, philo->data);
	philo->meal_total += 1;
	//printf("%d meal number %d\n", philo->philo_id, philo->meal_total);
	if (pthread_mutex_unlock(&(philo->left_fork->fork_mutex)) != 0)
	{
		write (2, "Error for left fork mutex unlock\n", 34);
		return (1);
	}
	//printf("--- %d has released the fork on his left [%d].\n", philo->philo_id, philo->left_fork->fork_id);
	if (pthread_mutex_unlock(&(philo->right_fork->fork_mutex)) != 0)
	{
		write (2, "Error for right fork mutex unlock\n", 35);
		return (1);
	}
	//printf("--- %d has released the fork on his right [%d].\n", philo->philo_id, philo->right_fork->fork_id);
	//philo->last_meal = new_timestamp(philo->data);
	//printf("last meal = %ld\n", philo->last_meal);
	usleep(philo->data->time_to_eat * 1000);
	return (0);
}

static int	sleeping(t_philo *philo)
{
	print_state("is sleeping\n", philo->philo_id, philo->data);
	usleep(philo->data->time_to_sleep * 1000);
	return (0);
}

static int	thinking(t_philo *philo)
{
	print_state("is thinking\n", philo->philo_id, philo->data);
	usleep(1000);
	return (0);
}
