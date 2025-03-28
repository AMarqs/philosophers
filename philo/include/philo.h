/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:33:48 by albmarqu          #+#    #+#             */
/*   Updated: 2025/03/28 14:32:45 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// bien

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
# include <sys/time.h>

//------------//
// STRUCTURES //---------------------------------------------------------------
//------------//

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				id;
	int				num_meals;
	long long		last_meal;
	pthread_t		thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int				num_philos;
	long long		time_die;
	long long		time_eat;
	long long		time_sleep;
	int				must_eat;
	//int				finished;
	int				dead;
	long long		init_time;
	pthread_mutex_t	*log;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}	t_data;

//-----------//
// FUNCTIONS //----------------------------------------------------------------
//-----------//

// philo.c
int			main(int argc, char **argv);

// check.c
int			check_args(int argc, char **argv);

// init.c
int			init_data(t_data *data, int argc, char **argv);
int			init_mutex(t_data *data);
void		init_philos(t_data *data);

// routine.c
void		*cycle(void *arg);

// monitor.c
void		*monitoring(void *arg);

// utils.c
long long	gettime(void);
void		sleep_time(long long time);
void		print_log(t_data *data, int philo, char *log);

// basic_functions.c
size_t		ft_strlen(const char *s);
int			is_digit(char *s);
int			ft_atoi(const char *str);
void		ft_putstr_fd(char *s, int fd);

// error.c
//void		free_all(t_data *data, t_philo *philo);
void		malloc_error(void);

void		*cycle(void *arg);

#endif