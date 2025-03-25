/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:44:42 by albmarqu          #+#    #+#             */
/*   Updated: 2025/03/25 22:37:00 by albmarqu         ###   ########.fr       */
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
		malloc_error();
		return (1);
	}
	pthread_mutex_init(&data->log, NULL);
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
	//data->finished = 0;
	data->dead = 0;
	if (init_mutex(data))
		return (1);
	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!data->philos)
	{
		malloc_error();
		return (1);
	}
	return (0);
}

void	init_philos(t_data *data)
{
	int			i;
	pthread_t	monitor_thread;

	i = 0;
	data->init_time = gettime();
	while (i <= data->num_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].num_meals = 0;
		data->philos[i].last_meal = data->init_time;
		data->philos[i].l_fork = &data->forks[i];
        data->philos[i].r_fork = &data->forks[(i + 1) % data->num_philos]; // NO ENTIENDO ESTO QUE QUIERE DECIR
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
}
