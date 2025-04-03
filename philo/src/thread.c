/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:53:49 by albmarqu          #+#    #+#             */
/*   Updated: 2025/04/03 16:13:32 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].num_meals = 0;
		data->philos[i].last_meal = data->init_time;
		data->philos[i].eating = 0;
		data->philos[i].meal_done = 0;
		data->philos[i].l_fork = &data->forks[i];
		if (i == data->num_philos - 1)
			data->philos[i].r_fork = &data->forks[0];
		else
			data->philos[i].r_fork = &data->forks[(i + 1)];
		data->philos[i].data = data;
		i++;
	}
	return (0);
}

void	one_philo(t_data *data)
{
	print_log(data, 1, "has taken a fork");
	sleep_time(data->time_die);
	print_log(data, 1, "died");
}

int	philo_thread(t_data *data)
{
	int			i;
	pthread_t	monitor_thread;

	data->init_time = gettime();
	if (data->init_time == 1 || init_philos(data))
		return (1);
	if (data->num_philos == 1)
	{
		one_philo(data);
		return (0);
	}
	if (pthread_create(&monitor_thread, NULL, &monitor, data) != 0)
		return (1);
	i = -1;
	while (++i < data->num_philos)
		if (pthread_create(&data->philos[i].thread, NULL,
				&philo_routine, &data->philos[i]) != 0)
			return (1);
	if (pthread_join(monitor_thread, NULL) != 0)
		return (1);
	i = -1;
	while (++i < data->num_philos)
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			return (1);
	return (0);
}
