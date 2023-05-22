/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:19:37 by mukhairu          #+#    #+#             */
/*   Updated: 2022/12/20 19:01:07 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_check_num(char *str, long num, int len)
{
	if (num == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		str[len] = '0' + (num % 10);
		num = num / 10;
		len--;
	}
	return (str);
}

static int	ft_count(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	num;
	int		n_len;
	char	*str;

	num = n;
	n_len = ft_count(n);
	str = (char *)ft_calloc(n_len + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[n_len--] = '\0';
	ft_check_num(str, num, n_len);
	return (str);
}
