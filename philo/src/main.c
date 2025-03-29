/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:15:26 by albmarqu          #+#    #+#             */
/*   Updated: 2025/03/29 20:10:15 by albmarqu         ###   ########.fr       */
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
		ft_putstr_fd("ERROR: Invalid arguments", 1);
		return (1);
	}
	// if (ft_atoi(argv[1]) == 1)
	// {
	// 	sleep_time((long long)ft_atoi(argv[2]));
	// 	long long time = gettime();
	// 	printf("%lld %d %s\n", time, 1, "died");
	// 	return (0);
	// }
	if (init_data(&data, argc, argv))
	{
		ft_putstr_fd("ERROR: Initialization fail", 1);
		return (1);
	}
	if (philo_thread(&data))
	{
		ft_putstr_fd("ERROR: Simulation fail", 1);
		return (1);
	}
	free_all(&data);
	return (0);
}
