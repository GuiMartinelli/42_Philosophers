/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:20:56 by guferrei          #+#    #+#             */
/*   Updated: 2022/03/03 08:27:33 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo_bonus.h"

int	print_msg(char *str, long int timestamp, char *color, t_data *data)
{
	if (data->philo.alive)
	{
		sem_wait(data->print);
		printf("%s%ld %d %s%s\n", color, timestamp, data->philo.id, str, RESET);
		sem_post(data->print);
		return (0);
	}
	return (1);
}

int	get_forks(t_data *data, t_philo *philo)
{
	if (philo->last_meal != data->inital_time)
	{
		while ((get_time() - data->philo.last_meal)
			< data->die * 0.75)
			usleep(100);
	}
	sem_wait(data->forks);
	sem_wait(data->forks);
	if (print_msg("has taken a fork", (get_time() - data->inital_time),
			YELLOW, data))
		return (1);
	if (print_msg("has taken a fork", (get_time() - data->inital_time),
			YELLOW, data))
		return (1);
	return (0);
}

void	*check_death(void *ptr)
{
	t_data	*data;

	data = ptr;
	while (data->philo.alive && data->philo.n_meals < data->n_meal)
	{
		if ((get_time() - data->philo.last_meal) >= data->die)
		{
			data->philo.alive = 0;
			sem_wait(data->print);
			printf("%s%ld %d died%s\n", RED,
				(get_time() - data->inital_time), data->philo.id, RESET);
			sem_close(data->forks);
			sem_unlink("/philo_forks");
			sem_close(data->print);
			sem_unlink("/philo_print");
			kill(0, SIGKILL);
			return (NULL);
		}
		else
			usleep(1000);
	}
	return (NULL);
}

int	eat(t_data *data, t_philo *philo)
{
	get_forks(data, philo);
	if (print_msg("is eating", (get_time() - data->inital_time), GREEN, data))
		return (1);
	philo->last_meal = get_time();
	philo->n_meals++;
	usleep(data->eat * 1000);
	sem_post(data->forks);
	sem_post(data->forks);
	return (0);
}

void	routine(t_data *data, t_philo *philo)
{
	pthread_t	th;

	pthread_create(&th, NULL, &check_death, data);
	if (philo->id % 2)
		usleep(1000);
	while (philo->n_meals < data->n_meal)
	{
		if (eat(data, philo))
			break ;
		if (print_msg("is sleeping",
				(get_time() - data->inital_time), PINK, data))
			break ;
		usleep(data->sleep * 1000);
		if (print_msg("is thinking",
				(get_time() - data->inital_time), BLUE, data))
			break ;
	}
	pthread_join(th, NULL);
	sem_close(data->forks);
	sem_close(data->print);
	sem_unlink("/philo_forks");
	sem_unlink("/philo_print");
}
