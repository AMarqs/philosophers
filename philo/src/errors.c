/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:19:27 by albmarqu          #+#    #+#             */
/*   Updated: 2025/03/29 19:46:33 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	if (data->forks)
	{
		while (i < data->num_philos)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->forks);
	}
	if (data->log)
	{
		pthread_mutex_destroy(data->log);
		free(data->log);
	}
	i = 0;
	if (data->philos)
	{
		while (i <= data->num_philos)
		{
			//free(data->philos[i].thread);
			free(data->philos[i].l_fork);
			free(data->philos[i].r_fork);
		}
		free(data->philos);
	}
	free(data);
}

// destroy_mutex(data);
// 	free_all(data, philo);

void	destroy_mutex(t_data *data)
{
	pthread_mutex_init(data->log, NULL);
}



// void	malloc_error()
// {
// 	ft_putstr_fd("Fatal error: malloc: memory allocation error\n", 2);
// }


// void	free_all(t_data *data, t_philo *philo)
// {
// 	if (data->philos[i].thread)
// 		free(philo->thread);
// 	if (philo->l_fork)
// 		free(philo->l_fork);
// 	if (philo->r_fork)
// 		free(philo->r_fork);
// 	if (philo)
// 		free(philo);
// 	if (data->philos)
// 		free(data->philos);
// 	if (data->forks)
// 		free(data->forks);
// 	if (data)
// 		free(data);
// }

