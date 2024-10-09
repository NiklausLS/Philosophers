/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:13:08 by nileempo          #+#    #+#             */
/*   Updated: 2024/10/09 22:17:15 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_fork
{
	pthread_mutex_t	fork_mutex;
}	t_fork;

typedef struct s_data
{
	int				philo_nbr;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				meal_nbr;
	int				stop;
	time_t			time_to_start;
	t_fork			*fork_array;
	struct s_philo	*philo_array;
	pthread_mutex_t	stop_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	meal_mutex;
}	t_data;

typedef struct s_philo
{
	int			philo_id;
	int			meal_total;
	time_t		last_meal;
	pthread_t	thread;
	t_fork		*left_fork;
	t_fork		*right_fork;
	t_data		*data;
}	t_philo;

int		init_data(t_data *data, int argc, char **argv);
void	make_forks_array(t_data *data);
void	make_philo_array(t_data *data);
void	make_philo_threads(t_data *data);
void	*philo_routine(void *arg);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
void	check_stop(t_data *data);
int		check_if_dead(t_philo *philo);
void	print_state(char *state, int philo_id, t_data *data);
time_t	get_timestamp(void);
void	lazy_sleep(long time, t_data *data);
int		check_meal_count(t_data *data);
void	handle_single_philosopher(t_philo *philo);

int		get_argv(int argc, char **argv, t_data *data);
int		check_all(int argc, char **argv);
int		check_argv(char **argv);
int		ft_atoi(char *str);

#endif
