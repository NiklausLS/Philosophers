/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 00:00:09 by nileempo          #+#    #+#             */
/*   Updated: 2024/02/13 01:05:04 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	cheap_atoi(char *str)
{
	int		i;
	long	nbr;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		nbr = (nbr * 10) + (str[i] - 48);
		i++;
	}
	return (nbr);
}

void	get_argv(int argc, char **argv, t_data *data)
{
	data->philo_nbr = cheap_atoi(argv[1]);
	printf("philo nbr = %d\n", data->philo_nbr);
	data->time_to_die = cheap_atoi(argv[2]);
	printf("death time = %d\n", data->time_to_die);
	data->time_to_eat = cheap_atoi(argv[3]);
	printf("time to eat = %d\n", data->time_to_eat);
	data->time_to_sleep = cheap_atoi(argv[4]);
	printf("time to sleep = %d\n", data->time_to_sleep);
	if (argc == 6)
	{
		data->eat_nbr = cheap_atoi(argv[5]);
		printf("number of mandatory lunches = %d\n", data->eat_nbr);
	}
}
