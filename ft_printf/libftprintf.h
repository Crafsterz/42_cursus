/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:20:18 by mukhairu          #+#    #+#             */
/*   Updated: 2022/12/21 18:28:03 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define DECIMAL "0123456789"
# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

int		ft_printf(const char *str, ...);
int		ft_putnbr(int n);
char	*ft_itoa_base(unsigned long long num, char *base);
int		ft_hexdec(unsigned int num, const char conv);
int		ft_uns_dec(unsigned int num);
int		ft_pointer(void *ptr);

//From libft
char	*ft_itoa(int n);
int		ft_putchar(char c); //changes were made
int		ft_putstr(char *s); //changes were made
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *str);

#endif
