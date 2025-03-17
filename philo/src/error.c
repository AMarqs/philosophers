/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alba <alba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:19:27 by alba              #+#    #+#             */
/*   Updated: 2025/03/17 22:12:26 by alba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(char *error, int return_value) // esto no me convence
{
	ft_putstr_fd("Error\n> ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd(".\n", 2);
	return (return_value);
}

void	malloc_error(void)
{
	ft_putstr_fd("Fatal error: malloc: memory allocation error\n", 2);
	exit(1); // está permitido exit???
}

void	free_all(t_philo *philo)
{
	if (simu && simu->mutex)
		free(simu->mutex);
	if (simu)
		free(simu);
	if (philo->forks)
		free(philo->forks);
	if (philo->philos)
		free(philo->philos);
	if (philo)
		free(philo);
}
