/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alba <alba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:18:35 by alba              #+#    #+#             */
/*   Updated: 2025/03/17 22:23:39 by alba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (1);
	while (i < 5)
		if (ft_atoi(argv[i++]) <= 0) // no sé si esto comprueba que solo sean números
			return (1);
	if (argv[5] && ft_atoi(argv[5]) < 0)
		return (1);
	return (0);
}
