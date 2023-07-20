/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:32:55 by mukhairu          #+#    #+#             */
/*   Updated: 2023/07/20 19:36:27 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || c == '+')
		return (1);
	return (0);
}

static int	ft_isnum(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (!ft_isdigit(str[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	init_data(t_data *data, char **argv)
{
	data->num_philo = atoi(argv[1]);
	data->num_fork = atoi(argv[1]);
	data->time_die = atoi(argv[2]);
	data->time_eat = atoi(argv[3]);
	data->time_sleep = atoi(argv[4]);
	data->eat_count = 0;
	data->time = 0;
	pthread_mutex_init(&data->death, NULL);
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->death, NULL);
	data->philo = malloc(sizeof(t_philo) * data->num_philo);
	if (!data->philo)
		return (0);
	if (argv[5])
	{
		data->eat_count = atoi(argv[5]);
		if (data->eat_count == 0)
			return (0);
	}
	return (1);
}

// void	*philosopher(void *arg)
// {
// 	t_philo	*philo;
// 	int		id;
// 	t_data	*data;

// 	philo = (t_philo *)arg;
// 	id = philo->id;
// 	data = philo->data;
// 	return (NULL);
// }

int	main(int argc, char **argv)
{
	t_data	data;

	if (!(argc >= 5 && argc <= 6))
		return (printf("Error! Too few or too many inputs\n"));
	if (!ft_isnum(argv))
		return (printf("Error the input are not acceptable value\n"));
	if (!init_data(&data, argv))
	{
		free(data.philo);
		return (printf("Error!"));
	}
	data.time = gettime();
	start(&data);
	printf("time: %ld\n", data.time);
	freeall(&data);
	printf("Yess!\n");
	return (0);
}
	// system("leaks philosophers");
	// while (num < atoi(argv[1]))
	// {
	// 	printf("philo: %d\n", num);
	// 	// philo.id = num;
	// 	num++;
	// }
