/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:23:26 by mukhairu          #+#    #+#             */
/*   Updated: 2022/12/22 18:34:53 by mukhairu         ###   ########.fr       */
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
		str = "(null)";
	while (str[total] != '\0')
	{
		total += ft_putchar(str[total]);
	}
	free(str);
	return (total);
}
