/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:52:43 by nileempo          #+#    #+#             */
/*   Updated: 2024/09/09 21:16:43 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	int		i;

	data = malloc(sizeof(t_data));
	if (!data)
	{
		write(2, "ERROR: Strutcutre memory allocation failed.\n", 45);
		return (1);
	}
	if (check_all(argc, argv) == 0)
	{
		init_data(data);
		get_argv(argc, argv, data);
		make_forks_array(data);
		make_philo_array(data);
		make_philo_threads(data);
		check_stop(data);
		i = 0;
		while (i < data->philo_nbr)
		{
			pthread_join(data->philo_array[i].thread, NULL);
			i++;
		}
	}
	return (0);
}
