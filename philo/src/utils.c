/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:21:09 by albmarqu          #+#    #+#             */
/*   Updated: 2025/04/03 13:34:13 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	gettime(void)
{
	struct timeval	time;
	long long		current_time;

	if (gettimeofday(&time, NULL) == -1)
	{
		printf("Error getting time");
		return (1);
	}
	current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (current_time);
}

void	sleep_time(long long time)
{
	long long	init;

	init = gettime();
	while ((gettime() - init) < time)
		usleep(100);
}

void	print_log(t_data *data, int philo_id, char *log)
{
	long long	actual_time;

	actual_time = gettime() - data->init_time;
	if (!data || !data->log)
		return ;
	pthread_mutex_lock(data->log);
	pthread_mutex_lock(data->dead_mutex);
	if (!data->dead)
		printf("%lld %d %s\n", actual_time, philo_id, log);
	pthread_mutex_unlock(data->dead_mutex);
	pthread_mutex_unlock(data->log);
}
