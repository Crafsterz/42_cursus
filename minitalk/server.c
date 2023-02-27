/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:57:14 by mukhairu          #+#    #+#             */
/*   Updated: 2023/02/24 12:15:27 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

void	ft_putnbr(int n)
{
	unsigned int	nb;
	char			c;

	if (n < 0)
	{
		write(1, "-", 1);
		nb = -n;
	}
	else
		nb = n;
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	c = nb + '0';
	write(1, &c, 1);
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

void	bin_receive(int signum)
{
	static int	bin_char;
	static int	i;

	if (signum == SIGUSR1)
		bin_char += 128;
	else if (signum == SIGUSR2)
		bin_char += 0;
	if (i < 7)
		bin_char >>= 1;
	i++;
	if (i == 8)
	{
		write(1, &bin_char, 1);
		bin_char = 0;
		i = 0;
	}
}

int	main(void)
{
	int	pid;

	signal(SIGUSR1, bin_receive);
	signal(SIGUSR2, bin_receive);
	ft_putstr("Server: Started\n");
	ft_putstr("Server: Waiting signals\n");
	pid = getpid();
	ft_putstr("PID: ");
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
