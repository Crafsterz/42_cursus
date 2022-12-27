/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:03:34 by mukhairu          #+#    #+#             */
/*   Updated: 2022/12/22 18:34:07 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_pointer(void *ptr)
{
	int				i;
	int				total;
	unsigned long	address;
	char			*str;

	total = 0;
	i = 0;
	address = (unsigned long)ptr;
	total += write(1, "0x", 2);
	str = ft_itoa_base(address, HEX_LOW);
	if (!str)
		str = "(null)";
	while (str[i] != '\0')
	{
		total += ft_putchar(str[i]);
		i++;
	}
	free(str);
	return (total);
}
