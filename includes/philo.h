/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:13:08 by nileempo          #+#    #+#             */
/*   Updated: 2024/04/23 13:58:53 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_data t_data;
typedef struct s_fork t_fork;

//philosophers id
typedef struct s_philo
{
	int			philo_id;
	int			meal_total;
	time_t		last_meal;
	int			alive;
	pthread_t	thread;
	t_fork		*left_fork;
	t_fork		*right_fork;
	t_data		*data;
	pthread_mutex_t	philo_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
}	t_philo;

//fork structure
typedef struct s_fork
{
	int				fork_id;
	pthread_mutex_t	fork_mutex;
}	t_fork;

//arguments data structure
typedef struct s_data
{
	int		philo_nbr;
	time_t	time_to_die;
	time_t	time_to_eat;
	time_t	time_to_sleep;
	int		meal_nbr;
	t_philo	*philo_array;
	t_fork	*fork_array;
	time_t	time_to_start;
}	t_data;

//init structure functions
void	init_data(t_data *data);
void	init_philo(t_philo *philo);

//parsing functions
int		check_argc(int argc);
int		check_argv(char **argv);
int		check_all(int argc, char **argv);
void	get_argv(int argc, char **argv, t_data *data);

//threads functions
void	make_philo_threads(t_data *data);
void	make_philo_array(t_data *data);
void	make_forks_array(t_data *data);

//events
void	*events(void *arg);
int		check_meal_count(t_data *data);
void	check_if_dead(t_philo *philo);
//void	*check_dinner(void *arg);
void	print_state(char *state, int philo_id, t_data *data);

//time managment
time_t	get_timestamp(void);
time_t	new_timestamp(t_data *data);

#endif