/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:19:27 by albmarqu          #+#    #+#             */
/*   Updated: 2025/03/28 17:28:19 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fail()
{
	int i;

	pthread_mutex_destroy(data->log, NULL);
	i = 0;;
	if (data->forks)
	{
		while (i < data->num_philos)
		{
			pthread_mutex_destroy(&data->forks[i], NULL);
			i++;
		}
		free(data->forks);
	}
	i = 0;
	if (data->philos)
	{
		while (i <= data->num_philos)
		free(data->philos);
	}
	
	free(data);
}





void	free_all(t_data *data, t_philo *philo)
{
	if (philo->thread)
		free(philo->thread);
	if (philo->l_fork)
		free(philo->l_fork);
	if (philo->r_fork)
		free(philo->r_fork);
	if (philo)
		free(philo);
	if (data->philos)
		free(data->philos);
	if (data->forks)
		free(data->forks);
	if (data)
		free(data);
}

void	destroy_mutex(t_data *data)
{
	pthread_mutex_init(data->log, NULL);
}
// destroy_mutex(data);
// 	free_all(data, philo);


void	malloc_error()
{
	ft_putstr_fd("Fatal error: malloc: memory allocation error\n", 2);
}
