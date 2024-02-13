/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:13:08 by nileempo          #+#    #+#             */
/*   Updated: 2024/02/13 15:20:35 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>

//fork structure
typedef struct s_fork
{
	int				fork_id;
	pthread_mutex_t	fork_mutex;
}	t_fork;

//philosophers id
typedef struct s_philo
{
	int			philo_id;
	pthread_t	thread;
	t_fork		*left_fork;
	t_fork		*right_fork;
}	t_philo;

//arguments data structure
typedef struct s_data
{
	int		philo_nbr;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		eat_nbr;
	t_philo	*philo_array;
	t_fork	*fork_array;
}	t_data;

//init structure functions
void	init_struct(t_data *data);

//parsing functions
int		check_argc(int argc);
int		check_argv(char **argv);
int		check_all(int argc, char **argv);
void	get_argv(int argc, char **argv, t_data *data);

//threads functions
void	init_philo_threads(t_philo *philo, int id, t_fork *fork);
void	make_philo_array(t_data *data);
void	make_forks_array(t_data *data);

//events
void	*events(void *arg);

#endif