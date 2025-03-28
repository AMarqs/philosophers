/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:15:04 by albmarqu          #+#    #+#             */
/*   Updated: 2025/03/28 14:35:35 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// bien

#include "philo.h"

// no sé por que esto no funciona

void	*monitoring(void *arg)
{
	int	i;

	i = 0;
    t_data *data = (t_data *)arg;
    while (!data->dead)
    {
		while (i < data->num_philos)
        {
            if (gettime() - data->philos[i].last_meal > data->time_die)
            {
                data->dead = 1;
                print_log(data, data->philos[i].id, "died");
                return (NULL);
            }
			i++;
        }
        usleep(1000);
    }
    return (NULL);
}