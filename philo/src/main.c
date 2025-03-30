/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:15:26 by albmarqu          #+#    #+#             */
/*   Updated: 2025/03/30 18:55:14 by albmarqu         ###   ########.fr       */
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

	if (check_args(argc, argv))
	{
		printf("ERROR: Invalid arguments");
		return (1);
	}
	if (init_data(&data, argc, argv))
	{
		printf("ERROR: Initialization fail");
		free_destroy(&data);
		return (1);
	}
	if (philo_thread(&data))
	{
		printf("ERROR: Simulation fail");
		free_destroy(&data);
		return (1);
	}
	free_destroy(&data);
	return (0);
}
