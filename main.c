/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:52:43 by nileempo          #+#    #+#             */
/*   Updated: 2024/02/13 15:19:41 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (check_all(argc, argv) == 0)
	{
		data = (t_data *)malloc(sizeof(t_data));
		if (!data)
		{
			write(2, "ERROR: Strutcutre memory allocation failed.\n", 45);
			return (1);
		}
		init_struct(data);
		get_argv(argc, argv, data);
		make_forks_array(data);
		make_philo_array(data);
		free(data);
		free(data->fork_array);
		free(data->philo_array);
	}
	return (0);
}
