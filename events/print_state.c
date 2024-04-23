/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 00:34:47 by nileempo          #+#    #+#             */
/*   Updated: 2024/04/23 02:09:07 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_state(char *state, int philo_id, t_data *data)
{
	time_t	timestamp;

	timestamp = new_timestamp(data);
	printf("%ld %d %s\n", timestamp, philo_id, state);
}
