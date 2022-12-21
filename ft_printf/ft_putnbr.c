/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:45:26 by mukhairu          #+#    #+#             */
/*   Updated: 2022/12/21 19:22:46 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(int n)
{
	int		nb;
	char	*num;

	nb = 0;
	num = ft_itoa(n);
	nb = ft_putstr(num);
	free(num);
	return (nb);
}
