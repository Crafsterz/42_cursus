/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:32:55 by mukhairu          #+#    #+#             */
/*   Updated: 2023/08/05 15:35:48 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *str)
{
	int		res;
	int		sign;
	int		i;
	char	*pstr;

	res = 0;
	sign = 1;
	i = 0;
	pstr = (char *)str;
	while (pstr[i] == 32 || (pstr[i] >= 9 && pstr[i] <= 13))
		i++;
	if (pstr[i] == '-' || pstr[i] == '+')
	{
		if (pstr[i] == '-')
			sign = -(sign);
		i++;
	}
	while (pstr[i] >= '0' && pstr[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

static int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || c == '+')
		return (1);
	return (0);
}

/*To check if the input to be an integer or not*/
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

/*To initialize the global value of the data for each philosophers in 
general. The mutex are init for later locks to prevent data race when
the program runs. There are 2 bool statements here to check when to 
printing of which philo has died. Is_dead is used when the philo was
detected to be dead. philo_dead however is used when one of them has
died. The malloc is used based on the size of the philo that was 
called in argv*/
int	init_data(t_data *data, char **argv)
{
	data->num_philo = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	data->is_dead = false;
	data->philo_dead = false;
	data->eat_count = 0;
	data->time = 0;
	data->philo_ate = 0;
	pthread_mutex_init(&data->death, NULL);
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->must_eat, NULL);
	pthread_mutex_init(&data->stop, NULL);
	data->philo = malloc(sizeof(t_philo) * data->num_philo);
	if (!data->philo)
		return (0);
	if (argv[5])
	{
		data->eat_count = ft_atoi(argv[5]);
		if (data->eat_count == 0)
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!(argc >= 5 && argc <= 6))
		return (printf("Error! Too few or too many inputs\n"));
	if (!ft_isnum(argv))
		return (printf("Error! The input are not acceptable\n"));
	if (!init_data(&data, argv))
	{
		free(data.philo);
		return (printf("Error!\n"));
	}
	data.time = gettime();
	data.philo->total_ate = 0;
	start(&data);
	freeall(&data);
	return (0);
}
	// system("leaks philosophers");
