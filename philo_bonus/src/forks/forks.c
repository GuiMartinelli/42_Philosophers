/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 07:51:33 by guferrei          #+#    #+#             */
/*   Updated: 2022/03/03 08:27:13 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo_bonus.h"

int	init_processes(t_data *data, int id)
{
	pid_t	pid;

	if (id <= data->n_philo)
	{
		pid = fork();
		if (pid == 0)
		{
			data->philo.id = id;
			routine(data, &data->philo);
			exit(0);
		}
		else
		{
			id += 1;
			init_processes(data, id);
			waitpid(-1, NULL, 0);
		}
	}
	return (0);
}
