/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:29:09 by mukhairu          #+#    #+#             */
/*   Updated: 2023/07/19 19:10:26 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	gettime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_sleep(unsigned long ms)
{
	long	time;

	time = gettime();
	while (gettime() - time < ms)
		usleep(ms / 10);
}

// int	phil_died(t_philo *philo, int num)
// {
// 	pthread_mutex_lock(&philo->data->death);
// 	if (num < philo->data->death)
// 	{
		
// 	}
// }
