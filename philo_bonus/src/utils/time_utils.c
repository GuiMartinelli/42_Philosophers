/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 09:54:19 by guferrei          #+#    #+#             */
/*   Updated: 2022/03/03 08:27:48 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo_bonus.h"

long int	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, 0))
		return (0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
