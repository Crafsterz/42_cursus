/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:50:02 by mukhairu          #+#    #+#             */
/*   Updated: 2023/08/05 15:33:18 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*The reduce make norminatte happy. Anyways, this is to reduce the call of the
same mutex call multiple times. I is used to lock the data from being used by
threads at the same time.*/
int	philo_dead(t_philo *philo, int nb)
{
	pthread_mutex_lock(&philo->data->death);
	if (nb)
		philo->data->philo_dead = true;
	if (philo->data->philo_dead == true)
	{
		pthread_mutex_unlock(&philo->data->death);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->death);
	return (0);
}
