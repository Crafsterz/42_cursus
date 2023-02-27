/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:10:58 by mukhairu          #+#    #+#             */
/*   Updated: 2023/02/23 20:01:58 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

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

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_response(int signum)
{
	if (signum == SIGUSR2)
		ft_putstr("Message to server received\n");
}

//SIGUSR1 return 1, SIGUSR2 return 0
void	sendinfo(int pid, char *str)
{
	static int	i;
	int			j;
	char		bin_char;

	while (str[i] != '\0')
	{
		j = 0;
		bin_char = str[i];
		while (j < 8)
		{
			if (bin_char % 2 != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			bin_char >>= 1;
			usleep(400);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*text;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		text = argv[2];
		ft_putstr("Client: Sending Signals\n");
		signal(SIGUSR1, ft_response);
		signal(SIGUSR2, ft_response);
		ft_putstr("Client: Signals Sent\n");
		sendinfo(pid, text);
	}
	return (0);
}
