/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:58:12 by albmarqu          #+#    #+#             */
/*   Updated: 2025/03/28 14:33:58 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// bien

#include "philo.h"

void	*cycle(void *arg)
{
	t_philo	*philo = (t_philo *)arg;
	t_data	*data = philo->data;

	while (!data->dead)
	{
		print_action(data, philo->id, "is thinking");

		pthread_mutex_lock(philo->l_fork);
		print_action(data, philo->id, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
		print_action(data, philo->id, "has taken a fork");
		print_action(data, philo->id, "is eating");
		philo->last_meal = gettime();
		sleep_time(data->time_eat);
		philo->num_meals++;

		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);

		print_action(data, philo->id, "is sleeping");
		sleep_time(data->time_sleep);
	}
}
