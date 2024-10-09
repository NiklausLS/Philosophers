/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:52:43 by nileempo          #+#    #+#             */
/*   Updated: 2024/10/09 22:14:24 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	int		i;

	if (check_all(argc, argv) == 1)
		return (1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	if (init_data(data, argc, argv) == 1)
		return (1);
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
	return (0);
}


