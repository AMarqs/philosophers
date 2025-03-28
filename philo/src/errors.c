/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:19:27 by albmarqu          #+#    #+#             */
/*   Updated: 2025/03/28 15:59:30 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	free_all(t_data *data, t_philo *philo)
// {
// 	if (data->forks)
// 		free(data->forks);
// 	if (data)
// 		free(data);
// 	if (philo->fork)
// 		free(philo->fork);
// 	if (philo)
// 		free(philo);
// }

void	malloc_error(void)
{
	ft_putstr_fd("Fatal error: malloc: memory allocation error\n", 2);
}


