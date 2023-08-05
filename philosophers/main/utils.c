/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:29:09 by mukhairu          #+#    #+#             */
/*   Updated: 2023/08/05 15:29:42 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*To get the time in general in miliseconds.*/
size_t	gettime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

/*To set the sleeping time or short delay in between they finishing task to 
allow other philo to do their tasks*/
void	ft_sleep(unsigned long ms)
{
	long	time;

	time = gettime();
	while (gettime() - time < ms)
		usleep(ms / 10);
}

//This is to print the log of what happened when the program runs. The mutex
//lock is added ensure only one thread to be printed. Unlocks once it is done
//printed.
void	logging(t_philo *philo, char *str)
{
	long	time;

	pthread_mutex_lock(&(philo->data->print));
	pthread_mutex_lock(&philo->data->stop);
	time = gettime() - philo->data->time;
	if (time >= 0 && time <= INT_MAX && (philo->data->is_dead == false
			|| !philo_dead(philo, 0)))
	{
		printf("%ld \t", gettime() - philo->data->time);
		printf("%d %s\n", philo->id + 1, str);
	}
	pthread_mutex_unlock(&philo->data->stop);
	pthread_mutex_unlock(&(philo->data->print));
}

/*Frees all the data that was preveiously created. At the sametime each 
mutex that was init mutex be destroy to prevent a leak.*/
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
	free(data->philo);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->death);
	pthread_mutex_destroy(&data->must_eat);
	pthread_mutex_destroy(&data->stop);
}

/*To check the deaths of the philos. If their time has reached their limit, it
philo->data->is_dead set to true.*/
void	phil_died(t_philo *philo)
{
	struct timeval	tv;
	int				t1;
	int				t2;

	pthread_mutex_lock(&philo->data->stop);
	gettimeofday(&tv, NULL);
	t1 = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	t2 = (philo->last_meal_tv.tv_sec * 1000)
		+ (philo->last_meal_tv.tv_usec / 1000);
	if ((size_t)(t1 - t2) >= (size_t)philo->data->time_die)
		philo->data->is_dead = true;
	pthread_mutex_unlock(&philo->data->stop);
}
