/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alba <alba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:33:48 by alba              #+#    #+#             */
/*   Updated: 2025/03/17 22:11:12 by alba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//---------//
// DEFINES //------------------------------------------------------------------
//---------//

//-----------//
// LIBRARIES //----------------------------------------------------------------
//-----------//

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h> // to get the current date

//------------//
// STRUCTURES //---------------------------------------------------------------
//------------//

typedef struct s_philo
{
	int		num_philos;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		must_eat;
	char	*philos;
	char	*forks;
}	t_philo;

//-----------//
// FUNCTIONS //----------------------------------------------------------------
//-----------//

// philo.c
int		main(int argc, char **argv);

// check.c
int		check_args(int argc, char **argv);

// init.c
t_philo	*init_args(char **argv);

// utils.c
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);

// error.c
int		print_error(char *error, int return_value);
void	malloc_error(void);

#endif