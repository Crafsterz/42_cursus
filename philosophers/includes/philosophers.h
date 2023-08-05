/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:28:35 by mukhairu          #+#    #+#             */
/*   Updated: 2023/08/05 15:34:11 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_data
{
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_philo;
	int				eat_count;
	int				philo_ate;
	bool			is_dead;
	bool			philo_dead;
	size_t			time;
	struct s_philo	*philo;
	pthread_mutex_t	print;
	pthread_mutex_t	death;
	pthread_mutex_t	must_eat;
	pthread_mutex_t	stop;
}					t_data;

typedef struct s_philo
{
	int				id;
	size_t			last_meal;
	struct timeval	last_meal_tv;
	int				total_ate;
	t_data			*data;
	pthread_t		threads;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	fork_l;
}					t_philo;

size_t	gettime(void);
void	*cycle(void *phil);
int		start(t_data *data);
void	ft_sleep(unsigned long ms);
void	logging(t_philo *philo, char *str);
void	freeall(t_data *data);
void	eating(t_philo *philo);
void	take_fork(t_philo *philo);
void	phil_died(t_philo *philo);
void	*check_death(void *philo);
int		philo_dead(t_philo *philo, int nb);

#endif // !PHILOSOPHERS_H
