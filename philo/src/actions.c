/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:26:12 by albmarqu          #+#    #+#             */
/*   Updated: 2025/04/03 17:27:52 by albmarqu         ###   ########.fr       */
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

void	take_forks(t_philo *philo)
{
	if (philo->l_fork < philo->r_fork)
	{
		pthread_mutex_lock(philo->l_fork);
		print_log(philo->data, philo->id, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
		print_log(philo->data, philo->id, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		print_log(philo->data, philo->id, "has taken a fork");
		pthread_mutex_lock(philo->l_fork);
		print_log(philo->data, philo->id, "has taken a fork");
	}
}

void	eat(t_philo	*philo)
{
	if (philo->meal_done == 1)
		return ;
	take_forks(philo);
	print_log(philo->data, philo->id, "is eating");
	pthread_mutex_lock(philo->data->eat_mutex);
	philo->eating = 1;
	pthread_mutex_unlock(philo->data->eat_mutex);
	pthread_mutex_lock(philo->data->meal_mutex);
	philo->last_meal = gettime();
	pthread_mutex_unlock(philo->data->meal_mutex);
	philo->num_meals++;
	sleep_time(philo->data->time_eat);
	pthread_mutex_lock(philo->data->eat_mutex);
	philo->eating = 0;
	pthread_mutex_unlock(philo->data->eat_mutex);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
