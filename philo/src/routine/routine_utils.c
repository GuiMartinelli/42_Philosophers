/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 09:56:51 by guferrei          #+#    #+#             */
/*   Updated: 2022/03/03 08:21:09 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	print_msg(char *str, long int timestamp, char *color, t_philo *philo)
{
	if (philo->args->is_alive
		&& (get_time() - philo->last_meal) < philo->args->die)
	{
		printf("%s%ld %d %s%s\n", color, timestamp, philo->id, str, RESET);
		return (0);
	}
	return (1);
}

int	is_satisfied(t_data *data)
{
	int		count;
	t_philo	*philo;

	count = 0;
	while (count < data->n_philo)
	{
		philo = data->philos + count;
		if (!philo->satisfied)
			return (0);
		count++;
	}
	return (1);
}

void	unlock_mutexes(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
