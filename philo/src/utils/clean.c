/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 03:00:04 by coder             #+#    #+#             */
/*   Updated: 2022/03/03 08:22:15 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	clean(t_data *data)
{
	int	count;

	count = 0;
	while (count < data->n_philo)
	{
		pthread_join(data->th[count], NULL);
		pthread_mutex_destroy(&data->forks[count]);
		count++;
	}
	pthread_join(data->checker, NULL);
	free(data->th);
	free(data->forks);
	free(data->philos);
}
