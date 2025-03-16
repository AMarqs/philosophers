/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alba <alba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:18:35 by alba              #+#    #+#             */
/*   Updated: 2025/03/16 21:11:20 by alba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		// ERROR: wrong number of arguments
		return (1);
	}
	while (i < 5)
	{
		if (ft_atoi(argv[i++]) <= 0)
		{
			// ERROR: wrong type of args, use only numbers
			return (1);
		}
	}
	if (argv[5] && argv[5] < 0)
	{
		// ERROR: wrong type of args, use only numbers
		return (1);
	}
	return (0);
}
