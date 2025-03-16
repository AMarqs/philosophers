/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alba <alba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:44:42 by alba              #+#    #+#             */
/*   Updated: 2025/03/16 20:59:06 by alba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_args(char **argv, t_philo *philo)
{
	philo->number_philos = argv[1];
	philo->time_die = argv[2];
	philo->time_eat = argv[3];
	philo->time_sleep = argv[4];
	philo->must_eat = argv[5];
}

void	initialization(void)
{
	
}
