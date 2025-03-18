/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alba <alba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:33:48 by alba              #+#    #+#             */
/*   Updated: 2025/03/18 21:29:13 by alba             ###   ########.fr       */
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

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				id;
	int				num_meals;
	long long		last_meal;
	pthread_mutex_t	*fork;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int				num_philos;
	long long		time_die;
	long long		time_eat;
	long long		time_sleep;
	int				must_eat;
	int				finished;
	int				died;
	long long		init_time;
	pthread_mutex_t	*forks;
	t_philo			*philo;
}	t_data;

//-----------//
// FUNCTIONS //----------------------------------------------------------------
//-----------//

// philo.c
int			main(int argc, char **argv);

// check.c
int			check_args(int argc, char **argv);

// init.c
int			initialization(t_data *data, t_philo *philo, char **argv);
int			init_data(t_data *data, char **argv);
int			init_mutex(t_data *data);
int			init_philos(t_data *data);

// utils.c
long long	gettime(void);

// basic_functions.c
size_t		ft_strlen(const char *s);
int			is_digit(char *s);
int			ft_atoi(const char *str);
void		ft_putstr_fd(char *s, int fd);

// error.c
void		free_all(t_data *data, t_philo *philo);
void		malloc_error(void);

#endif