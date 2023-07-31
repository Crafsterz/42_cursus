/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:49:16 by mukhairu          #+#    #+#             */
/*   Updated: 2023/07/31 17:41:20 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*The main life cycle of every philo. They are all the same to every philo. 
if any philo id is a value of a % 2 == 0, they must wait for their turn and
think. This is to prevent a deadlock or an early data race. While all is a
value of 1 it will continue until all their conditions are met.*/
void	*cycle(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	if (philo->id % 2 == 1)
	{
		logging(philo, "is thinking");
		ft_sleep(philo->data->time_eat, philo);
	}
	while (1)
	{
		if (check_death(philo))
			return (NULL);
		take_fork(philo);
		if (!eating(philo))
			return (NULL);
		if (philo->total_ate == philo->data->eat_count)
		{
			pthread_mutex_lock(&philo->data->death);
			if (++philo->data->philo_ate == philo->data->num_philo)
				pthread_mutex_unlock(&philo->data->death);
			pthread_mutex_unlock(&philo->data->death);
			return (NULL);
		}
		logging(philo, "is sleeping");
		ft_sleep(philo->data->time_sleep, philo);
		logging(philo, "is thinking");
	}
	return (NULL);
}

/*TO check the philos deaths accordingly. If one of them has died, they are 
logged but only 1 philo should be logged of their deaths. To prevent data
race, their death checks are locked. Mutext_lock stop are used to stop
another data race to the philo_dead as true.*/
int	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death);
	if (philo->data->is_dead == true)
	{
		pthread_mutex_unlock(&philo->data->death);
		phil_died(philo);
		logging(philo, "died");
		pthread_mutex_lock(&philo->data->stop);
		if (philo->data->philo_dead == false)
			philo->data->philo_dead = true;
		pthread_mutex_unlock(&philo->data->stop);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->death);
	return (0);
}

/*This is where the philos begin their eatime. Once they have finished eating,
their last_meal is reset that they can continue to eat again. At the sametime,
total_eat would also increase to accumalate the total of time they have eaten
Once they have finished eating, they drop their forks (pthread_unclock). 
Next on the list is sleeping. If they have nothing to do, they think.*/
int	eating(t_philo *philo)
{
	phil_died(philo);
	if (check_death(philo))
	{
		pthread_mutex_unlock(&philo->fork_l);
		pthread_mutex_unlock(philo->fork_r);
		return (0);
	}
	logging(philo, "is eating");
	pthread_mutex_lock(&philo->data->must_eat);
	philo->last_meal = gettime();
	philo->total_ate++;
	pthread_mutex_unlock(&philo->data->must_eat);
	ft_sleep(philo->data->time_eat, philo);
	pthread_mutex_unlock(&philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
	return (1);
}

/*The operation that allows the philos to their forks accordingly. Once a 
philosopher has taken both of their forks, it will be locked. Prevent the
other philosophers to take the other forks. The if statement is to check
if there are any philosophers nearby. They sleep the double amount just
to prevent a dead lock.*/
void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_l);
	logging(philo, "has taken a fork");
	if (philo->data->num_philo == 1)
	{
		ft_sleep(philo->data->time_die, philo);
		return ;
	}
	pthread_mutex_lock(philo->fork_r);
	logging(philo, "has taken a fork");
}

/*The start of the entire philo program. The date of time is documented
and later to be used to know the time of the philos. Later philos are 
init to know when was their last meal and id. fork_l is to represent 
current philo, fork_r are the shared forks from their right. They must
eat with both forks so that that they considered eating. pthread_create
is the function that creates the threads realing to the philo.
philo_join is the function that would later joins all the threads
together to prevent a leak. It's like free but for threads.*/
int	start(t_data *data)
{
	int	i;

	i = -1;
	data->time = gettime();
	while (++i < data->num_philo)
	{
		data->philo[i].id = i;
		data->philo[i].last_meal = gettime();
		data->philo[i].data = data;
		pthread_mutex_init(&(data->philo[i].fork_l), NULL);
		if (i == data->num_philo - 1)
			data->philo[i].fork_r = &data->philo[0].fork_l;
		else
			data->philo[i].fork_r = &data->philo[i + 1].fork_l;
		pthread_create(&data->philo[i].threads, NULL, &cycle,
			&(data->philo[i]));
	}
	i = -1;
	while (++i < data->num_philo)
	{
		if (pthread_join(data->philo[i].threads, NULL) != 0)
			return (0);
	}
	return (1);
}
