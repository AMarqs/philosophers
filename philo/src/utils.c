/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:21:09 by albmarqu          #+#    #+#             */
/*   Updated: 2025/03/25 22:20:06 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	gettime(void)
{
	struct timeval	time;
	long long		current_time;

	if (gettimeofday(&time, NULL) == -1)
	{
		ft_putstr_fd("Error getting time", 1);
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

void	print_log(t_data *data, int philo, char *log)
{
	long long	actual_time;

	actual_time = gettime() - data->init_time;
	pthread_mutex_lock(&data->log);
	if (!data->dead)
	{
		write(1, &actual_time, 1);
		write(1, &philo, 1);
		fd_putstr_fd(log, 1);
		write(1, '\n', 1);
	}
	pthread_mutex_unlock(&data->log);
}
