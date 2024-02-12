/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:13:08 by nileempo          #+#    #+#             */
/*   Updated: 2024/02/12 01:02:25 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_data
{
	int	philo_nbr;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	eat_nbr;
}	t_data;


//init structure functions
void	init_struct(t_data *data);

//parsing functions
int		check_argc(int argc);
int		check_argv(char **argv);
int		check_all(int argc, char **argv);
void	get_argv(int argc, char **argv, t_data *data);

#endif