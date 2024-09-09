/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 00:00:09 by nileempo          #+#    #+#             */
/*   Updated: 2024/09/09 21:14:59 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_atoi(char *str)
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
	data->philo_nbr = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->meal_nbr = ft_atoi(argv[5]);
	else
		data->meal_nbr = 0;
}
