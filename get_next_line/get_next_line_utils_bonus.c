/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:12:49 by mukhairu          #+#    #+#             */
/*   Updated: 2022/12/02 16:30:14 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int				len;
	unsigned char	*str;

	str = (unsigned char *)s;
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (str[len] == (unsigned char) c)
		{
			return ((char *)&str[len]);
		}
		len--;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		cat;
	int		count;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	count = (ft_strlen(s1) * sizeof(char)) + (ft_strlen(s2) * sizeof(char));
	str = malloc((count) + 1);
	if (!str)
		return (NULL);
	i = 0;
	cat = 0;
	str[count] = '\0';
	while (s1[i])
	{
		str[cat++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		str[cat++] = s2[i++];
	}
	str[cat] = '\0';
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	res = malloc(count * size);
	if (!res)
		return (NULL);
	ft_bzero(res, count * size);
	return (res);
}

void	ft_bzero( void *str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(char *)str = '\0';
		str++;
		i++;
	}
}
