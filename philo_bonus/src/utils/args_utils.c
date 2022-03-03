/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:55:39 by guferrei          #+#    #+#             */
/*   Updated: 2022/03/03 08:27:37 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo_bonus.h"

int	set_sempaphores(t_data *data)
{
	data->forks = sem_open("/philo_forks", O_CREAT | O_EXCL,
			644, data->n_philo);
	data->print = sem_open("/philo_print", O_CREAT | O_EXCL,
			644, 1);
	if (!data->forks || !data->print)
	{
		printf("Failed to create Forks\n");
		sem_close(data->forks);
		sem_unlink("/philo_forks");
		sem_close(data->print);
		sem_unlink("/philo_print");
		return (1);
	}
	return (0);
}

void	set_philo(t_data *data)
{
	data->philo.last_meal = data->inital_time;
	data->philo.n_meals = 0;
	data->philo.alive = 1;
}
