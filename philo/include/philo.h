/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:33:48 by albmarqu          #+#    #+#             */
/*   Updated: 2025/04/02 20:40:20 by albmarqu         ###   ########.fr       */
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
# include <sys/time.h>

//# define malloc(size) 0

//------------//
// STRUCTURES //---------------------------------------------------------------
//------------//

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				id;
	int				num_meals;
	long long		last_meal;
	int				eating;
	int				meal_done;
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
	int				dead;
	pthread_mutex_t	*dead_mutex;
	int				done;
	pthread_mutex_t	*done_mutex;
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

// thread.c
int			init_philos(t_data *data);
int			philo_thread(t_data *data);

// routine.c
void		*philo_routine(void *arg);
int			dead_check(t_data *data);
void		eat(t_philo	*philo);
void		zzz(t_philo	*philo);
void		think(t_philo	*philo);

// monitors.c
void		*monitor(void *arg);
int			dead_monitor(t_data *data);
int			meal_monitor(t_data *data);

// utils.c
long long	gettime(void);
void		sleep_time(long long time);
void		print_log(t_data *data, int philo, char *log);

// basic_functions.c
int			ft_strlen(char *s);
int			is_digit(char *s);
int			ft_atoi(char *str);

// errors.c
void		free_destroy(t_data *data);
void		free_all(t_data *data);
void		destroy_mutex(t_data *data);
void		free_mutex(t_data *data);

#endif