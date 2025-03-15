/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alba <alba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:19:27 by alba              #+#    #+#             */
/*   Updated: 2025/03/15 22:26:29 by alba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_err(char *error, int return_value) // esto no me convence
{
	ft_putstr_fd("Error\n> ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd(".\n", 2);
	return (return_value);
}
