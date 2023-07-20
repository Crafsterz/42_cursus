/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:29:09 by mukhairu          #+#    #+#             */
/*   Updated: 2023/07/20 19:38:45 by mukhairu         ###   ########.fr       */
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

void	logging(t_philo *philo, char *str)
{
	long	time;

	pthread_mutex_lock(&(philo->data->print));
	time = gettime() - philo->data->time;
	printf("log time: %ld, %s,\n", time, str);
	// if (time > 0 && time <= INT_MAX && !phil_died(philo))
	pthread_mutex_unlock(&(philo->data->print));
}

void	freeall(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_destroy(&(data->philo[i].fork_l));
		pthread_mutex_destroy(data->philo[i].fork_r);
		i++;
	}
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->death);
	pthread_mutex_destroy(&data->must_eat);
	free(data->philo);
}
// int	phil_died(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->data->death);
// 	if (num < philo->data->death)
// 	{
		
// 	}
// }
