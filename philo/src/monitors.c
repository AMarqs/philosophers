/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:15:04 by albmarqu          #+#    #+#             */
/*   Updated: 2025/04/03 13:32:34 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead_condition(t_data *data, int i)
{
	long long	dead_time;
	int			eating;

	pthread_mutex_lock(data->meal_mutex);
	dead_time = gettime() - data->philos[i].last_meal;
	pthread_mutex_unlock(data->meal_mutex);
	pthread_mutex_lock(data->eat_mutex);
	eating = data->philos[i].eating;
	pthread_mutex_unlock(data->eat_mutex);
	if (dead_time > data->time_die && eating == 0)
		return (1);
	return (0);
}

int	dead_monitor(t_data	*data)
{
	int			i;

	i = 0;
	while (i < data->num_philos)
	{
		if (dead_condition(data, i))
		{
			print_log(data, data->philos[i].id, "died");
			pthread_mutex_lock(data->dead_mutex);
			data->dead = 1;
			pthread_mutex_unlock(data->dead_mutex);
			return (1);
		}
		i++;
	}
	return (0);
}

int	meal_monitor(t_data	*data)
{
	int	i;

	i = -1;
	if (data->must_eat == -1)
		return (0);
	while (++i < data->num_philos)
		if (data->philos[i].num_meals == data->must_eat)
			data->philos[i].meal_done = 1;
	i = -1;
	pthread_mutex_lock(data->done_mutex);
	data->done = 0;
	while (++i < data->num_philos)
		if (data->philos[i].meal_done == 1)
			data->done++;
	pthread_mutex_unlock(data->done_mutex);
	if (data->done == data->num_philos)
	{
		pthread_mutex_lock(data->dead_mutex);
		data->dead = 1;
		pthread_mutex_unlock(data->dead_mutex);
		return (1);
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_data	*data;

	if (!arg)
		return (NULL);
	data = (t_data *)arg;
	while (1)
		if (dead_monitor(data) == 1 || meal_monitor(data) == 1)
			break ;
	return (arg);
}
