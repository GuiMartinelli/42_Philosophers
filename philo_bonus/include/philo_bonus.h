/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 02:23:03 by coder             #+#    #+#             */
/*   Updated: 2022/03/02 14:55:41 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <pthread.h>
# include <semaphore.h>
# include <stdio.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <signal.h>
# include "../include/colors.h"

typedef struct s_philo
{
	int				id;
	int				n_meals;
	int				alive;
	long int		last_meal;
}			t_philo;

typedef struct s_data
{
	int				n_philo;
	long int		inital_time;
	int				die;
	int				eat;
	int				sleep;
	int				n_meal;
	t_philo			philo;
	sem_t			*forks;
	sem_t			*print;
}			t_data;

int			set_arguments(int argc, char **argv, t_data *data);
void		set_philo(t_data *data);
int			set_sempaphores(t_data *data);
long int	get_time(void);
int			init_processes(t_data *data, int id);
void		routine(t_data *data, t_philo *philo);

#endif