/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:47:25 by nileempo          #+#    #+#             */
/*   Updated: 2024/09/30 12:02:40 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int init_data(t_data *data, int argc, char **argv)
{
    if (get_argv(argc, argv, data) == 1)
        return (1);
    data->stop = 0;
    data->time_to_start = get_timestamp();
    pthread_mutex_init(&data->stop_mutex, NULL);
    pthread_mutex_init(&data->print_mutex, NULL);
    pthread_mutex_init(&data->meal_mutex, NULL);
    return (0);
}

void make_forks_array(t_data *data)
{
    int i;

    i = 0;
    data->fork_array = malloc(data->philo_nbr * sizeof(t_fork));
    if (!data->fork_array)
        return;
    while (i < data->philo_nbr)
    {
        pthread_mutex_init(&data->fork_array[i].fork_mutex, NULL);
        i++;
    }
}

void make_philo_array(t_data *data)
{
    int i;

    i = 0;
    data->philo_array = malloc(data->philo_nbr * sizeof(t_philo));
    if (!data->philo_array)
        return;
    while (i < data->philo_nbr)
    {
        data->philo_array[i].philo_id = i + 1;
        data->philo_array[i].meal_total = 0;
        data->philo_array[i].last_meal = get_timestamp();
        data->philo_array[i].left_fork = &data->fork_array[i];
        data->philo_array[i].right_fork = &data->fork_array[(i + 1) % data->philo_nbr];
        data->philo_array[i].data = data;
        i++;
    }
}

void make_philo_threads(t_data *data)
{
    int i;

    i = 0;
    while (i < data->philo_nbr)
    {
        if (pthread_create(&data->philo_array[i].thread, NULL, philo_routine, &data->philo_array[i]) != 0)
        {
            write (2, "Error: thread making failed\n", 29);
        }
        i++;
    }
}
