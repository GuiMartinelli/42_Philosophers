/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 02:23:03 by coder             #+#    #+#             */
/*   Updated: 2022/03/01 09:37:07 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include "../include/colors.h"

typedef struct s_args
{
	int				die;
	int				eat;
	int				sleep;
	int				n_meal;
	int				is_alive;
	long int		inital_time;
}			t_args;

typedef struct s_philo
{
	int				id;
	int				n_meals;
	int				satisfied;
	long int		last_meal;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	t_args			*args;
}			t_philo;

typedef struct s_data
{
	int				n_philo;
	pthread_t		*th;
	pthread_t		checker;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}			t_data;

int			set_arguments(int argc, char **argv, t_args *args, t_data *data);
long int	get_time(void);
int			philo_init(t_data *data, t_args *args);
void		unlock_mutexes(t_philo *philo);
int			is_satisfied(t_data *data);
int			print_msg(char *str, long int timestamp,
				char *color, t_philo *philo);
void		*single_philo(void *ptr);
void		*routine(void *ptr);
void		*checker(void *ptr);
void		clean(t_data *data);

#endif