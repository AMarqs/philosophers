/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:15:04 by albmarqu          #+#    #+#             */
/*   Updated: 2025/03/29 19:17:17 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dead_monitor(void *arg)
{
	t_data			*data;
	int				i;

	if (!arg)
		return (NULL);
	data = (t_data *)arg;
	i = 0;
	while (!data->dead)
	{
		while (i < data->num_philos)
		{
			if (gettime() - data->philos[i].last_meal > data->time_die)
			{
				pthread_mutex_lock(data->dead_mutex);
				data->dead = 1;
				pthread_mutex_unlock(data->dead_mutex);
				print_log(data, data->philos[i].id, "died");
				return (NULL);
			}
			i++;
		}
		usleep(100);
	}
	return (NULL);
}

void	*meal_monitor(void *arg)
{
	t_data	*data;
	int		i;

	if (!arg)
		return (NULL);
	data = (t_data *)arg;
	i = 0;
	while (data->done != data->must_eat)
	{
		while (i < data->num_philos)
		{
			if (data->philos[i].num_meals == data->must_eat)
			{
				pthread_mutex_lock(data->done_mutex);
				data->done++;
				pthread_mutex_unlock(data->done_mutex);
				if (data->done == data->num_philos)
				{
					printf("HAN COMIDO TODOS"); //////////////////////////////////
					return (NULL);
				}
			}
		}
		usleep(100);
	}
	return (NULL);
}
