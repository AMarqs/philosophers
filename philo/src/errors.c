/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alba <alba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:19:27 by alba              #+#    #+#             */
/*   Updated: 2025/03/18 20:50:03 by alba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_data *data, t_philo *philo)
{
	if (data->forks)
		free(data->forks);
	if (data)
		free(data);
	if (philo->fork)
		free(philo->fork);
	if (philo)
		free(philo);
}

void	malloc_error(void)
{
	ft_putstr_fd("Fatal error: malloc: memory allocation error\n", 2);
}


