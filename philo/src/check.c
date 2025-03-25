/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:18:35 by albmarqu          #+#    #+#             */
/*   Updated: 2025/03/25 22:20:56 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int argc, char **argv)
{
	int	i;

	i = argc;
	if (argc < 5 || argc > 6)
		return (1);
	while (i > 1)
		if (is_digit(argv[i--]))
			return (1);
	if (ft_atoi(argv[1]) < 0)
		return (1);
	if (ft_atoi(argv[2]) <= 0 || ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0)
		return (1);
	if (argv[5] && ft_atoi(argv[5]) < 0)
		return (1);
	return (0);
}
