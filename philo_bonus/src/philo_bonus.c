/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 02:16:28 by coder             #+#    #+#             */
/*   Updated: 2022/03/03 07:47:40 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (set_arguments(argc, argv, &data))
		return (1);
	init_processes(&data, 1);
	sem_close(data.forks);
	sem_unlink("/philo_forks");
	sem_close(data.print);
	sem_unlink("/philo_print");
}
