/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:47:24 by mukhairu          #+#    #+#             */
/*   Updated: 2022/11/29 17:50:15 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Allocates (with malloc) and returns a substring from the string 's'
The substring begins at index 'start'and is of maximum size 'len'
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;

	i = 0;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!s || !ptr)
		return (NULL);
	while (start < ft_strlen((char *)s) && s[start + i] && i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*
#include <stdio.h>

int	main(void)
{
	char str[50] = "What'cha say?";
	char	*p;
	int	pos = 3;
	int	length = 5;

	p = ft_substr(str, pos, length);
	printf("%s\n", p);
	free(p);
	return (0);
}*/
