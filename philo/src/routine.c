/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:58:12 by albmarqu          #+#    #+#             */
/*   Updated: 2025/03/30 18:59:45 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo)
{
	print_log(philo->data, philo->id, "is thinking");
}

void	zzz(t_philo	*philo)
{
	print_log(philo->data, philo->id, "is sleeping");
	sleep_time(philo->data->time_sleep);
}

void	eat(t_philo	*philo)
{
	if (philo->meal_done == 1)
		return ;
	pthread_mutex_lock(philo->r_fork);
	print_log(philo->data, philo->id, "has taken a fork");
	if (philo->data->num_philos == 1)
	{
		usleep(philo->data->time_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	print_log(philo->data, philo->id, "has taken a fork");
	print_log(philo->data, philo->id, "is eating");
	philo->last_meal = gettime();
	philo->num_meals++;
	philo->eating = 1;
	sleep_time(philo->data->time_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

int	dead_check(t_data *data)
{
	pthread_mutex_lock(data->dead_mutex);
	if (data->dead == 1)
	{
		pthread_mutex_unlock(data->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(data->dead_mutex);
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	if (!arg)
		return (NULL);
	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		sleep_time(1);
	while (!dead_check(philo->data))
	{
		eat(philo);
		zzz(philo);
		think(philo);
	}
	return (arg);
}
