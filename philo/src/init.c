/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alba <alba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:44:42 by alba              #+#    #+#             */
/*   Updated: 2025/03/18 21:29:34 by alba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philos(t_data *data)
{
	int	i;

	i = 1;
	data->philo = malloc(sizeof(t_philo) * data->num_philos);
	if (data->philo == NULL)
	{
		malloc_error();
		return (1);
	}
	while (i <= data->num_philos)
	{
		data->philo[i].id = i;
		data->philo[i].num_meals = 0;
		data->philo[i].last_meal = data->init_time;
		data->philo[i].fork = malloc(sizeof(pthread_mutex_t) * data->num_philos);
		data->philo[i].data = data;
	}
	return (0);
}

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (!data->forks)
	{
		malloc_error();
		return (1);
	}
	while (i < data->num_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL); // hay que controlar si esto falla?
		i++;
	}
	return (0);
}

int	init_data(t_data *data, char **argv)
{
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
	{
		malloc_error();
		return (1);
	}
	data->num_philos = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->must_eat = ft_atoi(argv[5]);
	else
		data->must_eat = -1;
	data->finished = 0;
	data->died = 0;
	data->init_time = gettime();
	data->forks = NULL;
	if (init_mutex(data))
		return (1);
	return (0);
}

int	initialization(t_data *data, t_philo *philo, char **argv)
{
	if (init_data(data, argv))
		return (1);
	philo = (t_philo *)malloc(sizeof(t_philo) * data->num_philos);
	if (philo)
	{
		malloc_error();
		return (1);
	}
	if (init_philos(data))
		return (1);
	return (0);
}
