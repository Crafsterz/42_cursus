/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:09:02 by mukhairu          #+#    #+#             */
/*   Updated: 2022/12/22 18:38:01 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_hexdec(unsigned int num, const char conv)
{
	int		total;
	char	*str;

	total = 0;
	if (conv == 'x')
		str = ft_itoa_base(num, HEX_LOW);
	else
		str = ft_itoa_base(num, HEX_UP);
	if (!str)
		str = "(null)";
	while (str[total] != '\0')
	{
		total += ft_putchar(str[total]);
	}
	free(str);
	return (total);
}
