/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:16:05 by mukhairu          #+#    #+#             */
/*   Updated: 2022/12/21 16:58:12 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	ft_base_len(unsigned long long num, char *base)
{
	unsigned long long	base_len;
	size_t				len;

	len = 1;
	base_len = ft_strlen(base);
	while (num >= base_len)
	{
		num = num / base_len;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(unsigned long long num, char *base)
{
	int		len;
	int		base_len;
	char	*str;

	len = ft_base_len(num, base);
	base_len = ft_strlen(base);
	str = ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (len)
	{
		len = len - 1;
		str[len] = base[num % base_len];
		num = num / base_len;
	}
	return (str);
}
