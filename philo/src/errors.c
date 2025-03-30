/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:19:27 by albmarqu          #+#    #+#             */
/*   Updated: 2025/03/30 19:36:28 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_data *data)
{
	if (data->log)
		free(data->log);
	if (data->dead_mutex)
		free(data->dead_mutex);
	if (data->done_mutex)
		free(data->done_mutex);
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
}

void	destroy_mutex(t_data *data)
{
	int	i;

	i = -1;
	if (data->log)
		pthread_mutex_destroy(data->log);
	if (data->dead_mutex)
		pthread_mutex_destroy(data->dead_mutex);
	if (data->done_mutex)
		pthread_mutex_destroy(data->done_mutex);
	if (data->forks)
		while (++i < data->num_philos)
			pthread_mutex_destroy(&data->forks[i]);
}

void	free_destroy(t_data *data)
{
	destroy_mutex(data);
	free_all(data);
}
