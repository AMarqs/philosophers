/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alba <alba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:33:48 by alba              #+#    #+#             */
/*   Updated: 2025/03/15 22:29:19 by alba             ###   ########.fr       */
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
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}	t_philo;

struct	s_timeval
{
	time_t		tv_sec;
	suseconds_t	tv_usec;
};

//-----------//
// FUNCTIONS //----------------------------------------------------------------
//-----------//


#endif