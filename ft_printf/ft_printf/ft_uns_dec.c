/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:23:26 by mukhairu          #+#    #+#             */
/*   Updated: 2022/12/21 18:26:02 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_uns_dec(unsigned int num)
{
	int		total;
	char	*str;

	total = 0;
	str = ft_itoa_base(num, DECIMAL);
	if (!str)
		return (total);
	while (str[total] != '\0')
	{
		total += ft_putchar(str[total]);
	}
	free(str);
	return (total);
}
