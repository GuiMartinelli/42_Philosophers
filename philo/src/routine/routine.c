/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 21:25:04 by guferrei          #+#    #+#             */
/*   Updated: 2022/03/03 08:21:16 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	*checker(void *ptr)
{
	t_data	*data;
	t_philo	*aux;
	int		count;

	data = ptr;
	while (1)
	{
		count = 0;
		while (count < data->n_philo)
		{
			aux = data->philos + count;
			if ((get_time() - aux->last_meal) > aux->args->die)
			{
				printf("%s%ld %d died\n%s", RED,
					(get_time() - aux->args->inital_time), aux->id, RESET);
				aux->args->is_alive = 0;
				return (NULL);
			}
			if (is_satisfied(data))
				return (NULL);
			count++;
		}
		usleep(1000);
	}
	return (NULL);
}

static int	eat_n_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	if (print_msg("has taken a fork", (get_time() - philo->args->inital_time),
			YELLOW, philo))
		return (1);
	pthread_mutex_lock(philo->r_fork);
	if (print_msg("has taken a fork", (get_time() - philo->args->inital_time),
			YELLOW, philo))
		return (1);
	if (print_msg("is eating", (get_time() - philo->args->inital_time),
			GREEN, philo))
		return (1);
	philo->last_meal = get_time();
	philo->n_meals++;
	if (philo->n_meals == philo->args->n_meal)
		philo->satisfied = 1;
	usleep(philo->args->eat * 1000);
	if (print_msg("is sleeping", (get_time() - philo->args->inital_time),
			PINK, philo))
	{
		unlock_mutexes(philo);
		return (1);
	}
	unlock_mutexes(philo);
	return (0);
}

void	*single_philo(void *ptr)
{
	t_philo	*philo;

	philo = ptr;
	pthread_mutex_lock(philo->l_fork);
	if (print_msg("has taken a fork", (get_time() - philo->args->inital_time),
			YELLOW, philo))
		return (NULL);
	usleep(philo->args->die * 1000);
	printf("%s%ld %d died%s\n", RED,
		(get_time() - philo->args->inital_time), philo->id, RESET);
	pthread_mutex_unlock(philo->l_fork);
	return (NULL);
}

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = ptr;
	while (philo->n_meals != philo->args->n_meal && philo->args->is_alive)
	{
		if (philo->id % 2 > 0)
			usleep(1000);
		if (eat_n_sleep(philo))
			return (NULL);
		usleep(philo->args->sleep * 1000);
		if (print_msg("is thinking", (get_time() - philo->args->inital_time),
				BLUE, philo))
			return (NULL);
	}
	return (NULL);
}
