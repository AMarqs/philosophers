/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:44:42 by albmarqu          #+#    #+#             */
/*   Updated: 2025/03/30 18:35:50 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->log = malloc(sizeof(pthread_mutex_t));
	data->dead_mutex = malloc(sizeof(pthread_mutex_t));
	data->done_mutex = malloc(sizeof(pthread_mutex_t));
	if (!data->log || !data->dead_mutex || !data->done_mutex)
		return (1);
	pthread_mutex_init(data->log, NULL);
	pthread_mutex_init(data->dead_mutex, NULL);
	pthread_mutex_init(data->done_mutex, NULL);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (!data->forks)
		return (1);
	while (i < data->num_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
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
		printf("Fatal error: malloc: memory allocation error\n");
		return (1);
	}
	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!data->philos)
	{
		printf("Fatal error: malloc: memory allocation error\n");
		return (1);
	}
	return (0);
}
