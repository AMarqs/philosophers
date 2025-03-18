/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alba <alba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:15:26 by alba              #+#    #+#             */
/*   Updated: 2025/03/18 21:28:37 by alba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// //thread
// pthread_t thread;
// pthread_create(&thread, NULL, 'funcion', 'argumento funcion');
// pthread_join(thread, NULL);

// if (pthread_create(&thread, NULL, 'funcion', 'argumento funcion') != 0)
// {
// 	// error
// 	return (1);
// }
// if (pthread_join(thread, NULL) != 0)
// {
// 	// error
// 	return (1);
// }


// // mutex
// pthread_mutex_t mutex;
// pthread_mutex_init(&mutex, NULL);
// pthread_mutex_lock(&mutex);
// pthread_mutex_unlock(&mutex);
// pthread_mutex_destroy(&mutex);


int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	philo;

	if (check_args(argc, argv))
	{
		ft_putstr_fd("ERROR: Invalid arguments", 1);
		return (1);
	}
	if (initialization(&data, &philo, argv))
	{
		ft_putstr_fd("ERROR: Initialization fail", 1);
		return (1);
	}
	// if (thread_routine(&data, &philo))
	// {
	// 	ft_putstr_fd("ERROR: Simulation fail", 1);
	// 	return (1);
	// }
	free_all(&data, &philo);
	return (0);
}
