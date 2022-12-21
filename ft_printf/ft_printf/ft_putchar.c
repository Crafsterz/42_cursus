/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:10:14 by mukhairu          #+#    #+#             */
/*   Updated: 2022/12/21 19:22:11 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// void	ft_putchar_fd(char c, int fd)
// {
// 	write(fd, &c, 1);
// }

//ft_putchar_fd(c, 1);
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
