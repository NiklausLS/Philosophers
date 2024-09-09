/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:44:02 by nileempo          #+#    #+#             */
/*   Updated: 2024/09/09 08:06:22 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_argc(int argc)
{
	if (argc < 5)
	{
		write(2, "ERROR: not enought arguments.\n", 31);
		return (1);
	}
	if (argc > 6)
	{
		write(2, "ERROR: to many arguments.\n", 27);
		return (1);
	}
	return (0);
}

static int	check_argv(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				write(2, "ERROR: this is not a valid argument.\n", 38);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_all(int argc, char **argv)
{
	if (check_argc(argc) == 0)
	{
		if (check_argv(argv) == 0)
			return (0);
	}
	return (1);
}
