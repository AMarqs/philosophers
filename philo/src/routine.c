/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:58:12 by albmarqu          #+#    #+#             */
/*   Updated: 2025/03/29 19:53:06 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(void *arg)
{
	t_philo	*philo;

	if (!arg)
		return ;
	philo = (t_philo *)arg;
	print_log(philo->data, philo->id, "is thinking");
}

void	zzz(void *arg)
{
	t_philo	*philo;

	if (!arg)
		return ;
	philo = (t_philo *)arg;
	print_log(philo->data, philo->id, "is sleeping");
	sleep_time(philo->data->time_sleep);
}

void	eat(void *arg)
{
	t_philo	*philo;

	if (!arg)
		return ;
	philo = (t_philo *)arg;
	pthread_mutex_lock(philo->l_fork);
	print_log(philo->data, philo->id, "has taken a fork");
	pthread_mutex_lock(philo->r_fork);
	print_log(philo->data, philo->id, "has taken a fork");
	print_log(philo->data, philo->id, "is eating");
	philo->last_meal = gettime();
	sleep_time(philo->data->time_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	philo->num_meals++;
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	if (!arg)
		return (NULL);
	philo = (t_philo *)arg;
	data = philo->data;
	if (philo->id % 2 == 0)
		sleep_time(philo->data->time_eat);
	while (data->dead == 0 && data->done < data->num_philos)
	{
		eat(philo);
		zzz(philo);
		think(philo);
	}
	return (arg);
}
