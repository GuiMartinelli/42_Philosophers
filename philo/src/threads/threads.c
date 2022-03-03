/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 02:45:11 by coder             #+#    #+#             */
/*   Updated: 2022/03/03 08:22:06 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	philo_data(t_data *data, t_args *args, int count)
{
	t_philo	*aux;

	aux = data->philos + count;
	aux->id = count + 1;
	aux->n_meals = 0;
	aux->args = args;
	aux->last_meal = aux->args->inital_time;
	aux->satisfied = 0;
	if (count == 0)
	{
		if (data->n_philo > 1)
			aux->r_fork = &data->forks[(data->n_philo - 1)];
		aux->l_fork = &data->forks[count];
	}
	else
	{
		aux->r_fork = &data->forks[count - 1];
		aux->l_fork = &data->forks[count];
	}
}

static int	create_mutex(t_data *data)
{
	int	count;

	count = 0;
	data->forks = malloc((data->n_philo + 1) * sizeof(pthread_mutex_t));
	if (!data->forks)
		return (1);
	while (count < data->n_philo)
	{
		if (pthread_mutex_init(&data->forks[count], NULL))
		{
			free(data->forks);
			return (1);
		}
		count++;
	}
	return (0);
}

static int	create_threads(t_data *data, t_args *args)
{
	int	count;

	count = 0;
	data->th = malloc((data->n_philo + 1) * sizeof(pthread_t));
	data->philos = malloc((data->n_philo + 1) * sizeof(t_philo));
	if (!data->th || !data->philos)
		return (1);
	while (count < data->n_philo)
	{
		philo_data(data, args, count);
		if (data->n_philo == 1)
		{
			if (pthread_create(&data->th[count],
					NULL, &single_philo, &data->philos[count]))
				return (1);
			return (0);
		}
		if (pthread_create(&data->th[count],
				NULL, &routine, &data->philos[count]))
			return (1);
		count++;
	}
	if (pthread_create(&data->checker, NULL, &checker, data))
		return (1);
	return (0);
}

int	philo_init(t_data *data, t_args *args)
{
	if (create_mutex(data))
	{
		write(2, "Failed to init mutexes\n", 24);
		return (1);
	}
	if (create_threads(data, args))
	{
		write(2, "Failed to create threads\n", 26);
		free(data->forks);
		return (1);
	}
	return (0);
}
