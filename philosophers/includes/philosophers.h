/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:28:35 by mukhairu          #+#    #+#             */
/*   Updated: 2023/07/19 19:57:07 by mukhairu         ###   ########.fr       */
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
	int				num_fork;
	int				eat_count;
	size_t			time;
	struct s_philo	*philo;
	pthread_mutex_t	print;
	pthread_mutex_t	death;
	pthread_mutex_t	must_eat;
}					t_data;

typedef struct s_philo
{
	int				id;
	long			last_meal;
	int				total_ate;
	bool			eating;
	t_data			*data;
	pthread_t		threads;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	fork_l;
}					t_philo;

// int	check_errors(char **strs);
size_t	gettime(void);
void	*cycle(void *phil);
int		start(t_data *data);
// typedef struct s_philoId

#endif // !PHILOSOPHERS_H
