/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:49:16 by mukhairu          #+#    #+#             */
/*   Updated: 2023/07/20 19:50:05 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

	// while (i < 3)
	// {
	// 	printf("philo id: %d\n", philo->id);
	// 	i++;
	// }
void	*cycle(void *ph)
{
	t_philo	*philo;
	// t_data	data;

	philo = (t_philo *)ph;
	if (philo->id % 2 == 0)
		ft_sleep(philo->data->time_eat);
	logging(philo, "Test");
	
	// while (!(is_dead()))

	return (NULL);
}

int	start(t_data *data)
{
	int	i;

	i = -1;
	data->time = gettime();
	while (++i < data->num_philo)
	{
		data->philo[i].id = i;
		data->philo[i].last_meal = 0;
		data->philo[i].eating = false;
		data->philo[i].total_ate = 0;
		data->philo[i].data = data;
		pthread_mutex_init(&(data->philo[i].fork_l), NULL);
		if (i == data->num_philo - 1)
			data->philo[i].fork_r = &data->philo[i].fork_l;
		else
			data->philo[i].fork_r = &data->philo[i + 1].fork_l;
		pthread_create(&data->philo[i].threads, NULL, &cycle, &(data->philo[i]));
	}
	i = -1;
	while (++i < data->num_philo)
	{
		if (pthread_join(data->philo[i].threads, NULL) != 0)
			return (0);
	}
	return (1);
}
