/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 09:11:59 by guferrei          #+#    #+#             */
/*   Updated: 2022/03/03 09:43:12 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	ft_atoi(const char *ptr)
{
	long long int	n;

	n = 0;
	if (*ptr == '-')
		return (-1);
	else if (*ptr == '+')
		ptr++;
	while (*ptr >= 48 && *ptr <= 57)
	{
		n = n * 10;
		n = n + ((int)*ptr - 48);
		ptr++;
	}
	if (n > 2147483648)
	{
		printf("Error: INT Overflow!!\n");
		return (-1);
	}
	return ((int)n);
}

static int	is_valid(char *arg)
{
	while (*arg)
	{
		if (*arg < 48 || *arg > 57)
			return (0);
		arg++;
	}
	return (1);
}

static int	set_variable(char *arg)
{
	if (!is_valid(arg))
	{
		printf("All arguments must be numerical\n");
		return (-1);
	}
	return (ft_atoi(arg));
}

int	set_arguments(int argc, char **argv, t_args *args, t_data *data)
{
	args->n_meal = 99999999;
	if (argc < 5 || argc > 6)
	{
		printf("Invalid number of arguments\n");
		return (-1);
	}
	data->n_philo = set_variable(argv[1]);
	args->die = set_variable(argv[2]);
	args->eat = set_variable(argv[3]);
	args->sleep = set_variable(argv[4]);
	args->inital_time = get_time();
	args->is_alive = 1;
	if (argv[5])
		args->n_meal = set_variable(argv[5]);
	if (data->n_philo < 1 || args->eat < 1 || args->die < 1
		|| args->sleep < 1 || args->n_meal < 0)
		return (1);
	return (0);
}
