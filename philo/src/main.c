/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:15:26 by albmarqu          #+#    #+#             */
/*   Updated: 2025/04/03 13:33:20 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
