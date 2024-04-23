/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 00:48:52 by nileempo          #+#    #+#             */
/*   Updated: 2024/04/23 02:06:53 by nileempo         ###   ########.fr       */
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
	if (philo->data->meal_nbr == 0)
		return (NULL);
	if (philo->philo_id % 2)
		usleep(5000);
	while (1)
	{	
		printf("test avant check_meal\n");
		check_meal_count(philo->data);
		check_if_dead(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (arg);
}

static int	eating(t_philo *philo)
{
	if (pthread_mutex_lock(&(philo->left_fork->fork_mutex)) != 0)
	{
		write (2, "Error for left mutex lock\n", 27);
		return (1);
	}
	//printf("%d has taken the fork on his left [%d].\n", philo->philo_id, philo->left_fork->fork_id);
	print_state("has taken a fork\n", philo->philo_id, philo->data);
	if (pthread_mutex_lock(&(philo->right_fork->fork_mutex)) != 0)
	{
		write (2, "Error for right mutex lock\n", 28);
		return (1);
	}
	print_state("has taken a fork\n", philo->philo_id, philo->data);
	//printf("%d has taken the fork on his right [%d].\n", philo->philo_id, philo->right_fork->fork_id);
	//printf("time_to_eat = %d\n", philo->data->time_to_eat * 1000);
	//printf("%d is eating.\n", philo->philo_id);
	philo->meal_total += 1;
	printf("Philo %d have eaten %d times\n", philo->philo_id, philo->meal_total);
	usleep(philo->data->time_to_eat * 1000);
	philo->meal_total += 1;
	printf("Philo %d have eaten %d times\n", philo->philo_id, philo->meal_total);
	printf("%d meal number %d\n", philo->philo_id, philo->meal_total);
	if (pthread_mutex_unlock(&(philo->left_fork->fork_mutex)) != 0)
	{
		write (2, "Error for left mutex unlock\n", 27);
		return (1);
	}
	printf("%d has released the fork on his left [%d].\n", philo->philo_id, philo->left_fork->fork_id);
	if (pthread_mutex_unlock(&(philo->right_fork->fork_mutex)) != 0)
	{
		write (2, "Error for right mutex unlock\n", 30);
		return (1);
	}
	printf("%d has released the fork on his right [%d].\n", philo->philo_id, philo->right_fork->fork_id);
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
	usleep(100);
	return (0);
}

/*
static int	dying(t_philo *philo)
{

}*/