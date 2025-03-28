/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:44:42 by albmarqu          #+#    #+#             */
/*   Updated: 2025/03/28 17:26:27 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (!data->forks)
	{
		ft_putstr_fd("Fatal error: malloc: memory allocation error\n", 2);
		free(data);
		return (1);
	}
	while (i < data->num_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(data->log, NULL);
	return (0);
}

int	init_data(t_data *data, int argc, char **argv)
{
	data->num_philos = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->must_eat = ft_atoi(argv[5]);
	else
		data->must_eat = -1;
	data->dead = 0;
	if (init_mutex(data))
		return (1);
	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!data->philos)
	{
		ft_putstr_fd("Fatal error: malloc: memory allocation error\n", 2);
		fail();
		return (1);
	}
	return (0);
}

int	init_philos(t_data *data)
{
	int			i;
	pthread_t	monitor_thread;

	i = 0;
	if ((data->init_time = gettime()) == 1)
	{
		fail();
		return (1);
	}
	while (i <= data->num_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].num_meals = 0;
		data->philos[i].last_meal = data->init_time;
		data->philos[i].l_fork = &data->forks[i];
		if (i == data->num_philos - 1)
            data->philos[i].r_fork = &data->forks[0];
        else
            data->philos[i].l_fork = &data->forks[(i + 1)];
		data->philos[i].data = data;
		pthread_create(&data->philos[i].thread, NULL, cycle, &data->philos[i]);
	}
	pthread_create(&monitor_thread, NULL, monitoring, data);
    pthread_join(monitor_thread, NULL);
	i = 0;
	while (i < data->num_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	return (0);
}
