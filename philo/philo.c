/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alba <alba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:15:26 by alba              #+#    #+#             */
/*   Updated: 2025/03/15 22:27:08 by alba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;

	number_of_philosophers = argv[0];
	time_to_die = argv[1];
	time_to_eat = argv[2];
	time_to_sleep = argv[3];

	// creo los philos
	int	i;

	i = 1;
	while (i <= number_of_philosophers)
	{
		pthread_create(&thid, NULL, thread, "thread i");
		i++;
	}
}
