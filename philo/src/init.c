/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alba <alba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:44:42 by alba              #+#    #+#             */
/*   Updated: 2025/03/17 22:11:32 by alba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_args(char **argv)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		malloc_error();
	philo->num_philos = ft_atoi(argv[1]);
	philo->time_die = ft_atoi(argv[2]);
	philo->time_eat = ft_atoi(argv[3]);
	philo->time_sleep = ft_atoi(argv[4]);
	philo->must_eat = ft_atoi(argv[5]);
	return (philo);
}

void	initialization(t_philo *philo)
{
	philo->philos = (t_philo *)malloc(sizeof(t_philo) * philo->num_philos);
	if (!philo->philos)
		malloc_error();
	philo->forks = (t_fork *)malloc(sizeof(t_philo) * philo->num_philos);
	if (!philo->forks)
		malloc_error();
}
