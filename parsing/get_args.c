/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 00:00:09 by nileempo          #+#    #+#             */
/*   Updated: 2024/09/30 12:02:52 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(char *str)
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

int	get_argv(int argc, char **argv, t_data *data)
{
	data->philo_nbr = ft_atoi(argv[1]);
	if (data->philo_nbr <= 0)
	{
		write (2, "Error: number of philosopher can't be below 1\n", 47);
		return (1);
	}
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->meal_nbr = ft_atoi(argv[5]);
	else
		data->meal_nbr = -1;
	return (0);
}
