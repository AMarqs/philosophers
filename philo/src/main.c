/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:15:26 by albmarqu          #+#    #+#             */
/*   Updated: 2025/03/28 14:40:30 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// bien

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

// holaaaaaa

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_args(argc, argv))
	{
		ft_putstr_fd("ERROR: Invalid arguments", 1);
		return (1);
	}
	if (init_data(&data, argc, argv))
	{
		ft_putstr_fd("ERROR: Initialization fail", 1);
		return (1);
	}
	init_philos(&data);

// no se por que esto no funciona
	
	// if (routine(&data))
	// {
	// 	ft_putstr_fd("ERROR: Simulation fail", 1);
	// 	return (1);
	// }
	free_all(&data);
	// // Step 3: Cleanup resources
    // for (int i = 0; i < data.num_philos; i++)
    //     pthread_mutex_destroy(&data.forks[i]);
    // pthread_mutex_destroy(&data.print_mutex);
    // free(data.forks);
    // free(data.philos);
	return (0);
}