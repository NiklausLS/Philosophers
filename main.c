/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:52:43 by nileempo          #+#    #+#             */
/*   Updated: 2024/04/23 13:55:20 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

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

		//START
		//free(data->fork_array);
		//free(data->philo_array);
		//free(data);
	}
	return (0);
}
