/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:49:16 by mukhairu          #+#    #+#             */
/*   Updated: 2023/07/18 18:51:43 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	start(t_data *data)
{
	int	i;

	i = 0;
	data->time = gettime();
	while (i < data->num_philo)
	{
		data->philo[i].id = i;
		data->philo[i].last_meal = 0;
		data->philo[i].eating = false;
		data->philo[i].total_ate = 0;
		data->philo[i].data = data;
		pthread_mutex_init(&(data->philo[i].fork_l), NULL);
		if (i == data->num_philo - 1)
		{
			data->philo[i].fork_r = &data->philo[i].fork_l;
		}
		else
		{
			data->philo[i].fork_r = &data->philo[i + 1].fork_l;
		}

		i++;
	}
	return (1);
}
