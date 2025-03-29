/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:44:42 by albmarqu          #+#    #+#             */
/*   Updated: 2025/03/29 20:12:10 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (!data->forks)
		return (1);
	while (i < data->num_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	data->log = malloc(sizeof(pthread_mutex_t));
	if (!data->log)
		return (1);
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
	data->done = 0;
	if (init_mutex(data))
	{
		ft_putstr_fd("Fatal error: malloc: memory allocation error\n", 2);
		free_all(data);
		return (1);
	}
	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!data->philos)
	{
		ft_putstr_fd("Fatal error: malloc: memory allocation error\n", 2);
		free_all(data);
		return (1);
	}
	return (0);
}

int	init_philos(t_data *data)
{
	int			i;

	i = 0;
	while (i < data->num_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].num_meals = 0;
		data->philos[i].last_meal = data->init_time;
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

int	philo_thread(t_data *data)
{
	int			i;
	pthread_t	dead_thread;
	pthread_t	meal_thread;

	i = 0;
	data->init_time = gettime();
	if (data->init_time == 1)
	{
		free_all(data);
		return (1);
	}
	if (init_philos(data))
	{
		free_all(data);
		return (1);
	}
	while (i < data->num_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL,
				philo_routine, &data->philos[i]) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < data->num_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	if (pthread_create(&dead_thread, NULL, dead_monitor, data) != 0)
		return (1);
	// pthread_create(&dead_thread, NULL, dead_monitor, data);
	pthread_join(dead_thread, NULL);
	if (pthread_create(&meal_thread, NULL, meal_monitor, data) != 0)
		return (1);
	// pthread_create(&meal_thread, NULL, meal_monitor, data);
	pthread_join(meal_thread, NULL);
	return (0);
}
