/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 02:16:28 by coder             #+#    #+#             */
/*   Updated: 2022/02/24 15:30:56 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_args	args;

	if (set_arguments(argc, argv, &args, &data))
		return (1);
	if (philo_init(&data, &args))
		return (1);
	clean(&data);
}
