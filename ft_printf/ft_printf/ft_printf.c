/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:44:53 by mukhairu          #+#    #+#             */
/*   Updated: 2022/12/21 19:21:20 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_checkconversion(va_list list, const char str)
{
	int	tot_char;

	tot_char = 0;
	if (str == 'c')
		tot_char += ft_putchar(va_arg(list, int));
	if (str == 's')
		tot_char += ft_putstr(va_arg(list, char *));
	if (str == 'p')
		tot_char += ft_pointer(va_arg(list, void *));
	if (str == 'd' || str == 'i')
		tot_char += ft_putnbr(va_arg(list, int));
	if (str == 'u')
		tot_char += ft_uns_dec(va_arg(list, unsigned long));
	if (str == 'x' || str == 'X')
		tot_char += ft_hexdec(va_arg(list, unsigned long), str);
	if (str == '%')
		tot_char += ft_putchar('%');
	return (tot_char);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		total;

	va_start (list, str);
	i = 0;
	total = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			total += ft_checkconversion(list, str[i + 1]);
			i++;
		}
		else
			total += ft_putchar(str[i]);
		i++;
	}
	va_end(list);
	return (total);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char *str1 = "123456";
// 	// int str1 = 50;
// 	char str2 = 'S';
// 	int ori_count = 0;
// 	int ft_count = 0;

// 	// printf("printf, str1 = %d\n", str1);
// 	// ori_count = printf("printf, str2 = %c\n%c%c\n", str2,str2,str2);
// 	// ft_printf("ft_printf, str1 = %d\n", str1);
// 	// ft_count = ft_printf("ft_printf, str2 = %c\n%c%c\n", str2,str2,str2);
// 	// ft_printf("ft_printf, %%\n");

// 	ori_count = printf("no, str1 = %p\n",str1);
// 	ft_count = ft_printf("ft, str1 = %p\n",str1);

// 	printf("ori_count = %d, ft_count = %d", ori_count, ft_count);
// 	return (0);
// }
