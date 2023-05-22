/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:25:17 by mukhairu          #+#    #+#             */
/*   Updated: 2023/05/19 15:45:32 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
To replace a the old char into a new char. For example 
ft_replace_char(array, y, a). the char 'y' will later be replaced with 'a'.
However, this fuction is not used in the program.
*/
void	ft_replace_char(char *str, char old, char new)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == old)
			str[i] = new;
		i++;
	}
}

/*
The extention to the ft_str_checker. It will check
is a char or a int. Other than that if it contains '-' or '+' it will
return normally. Else it will the check will end and stops the program
*/
static int	str_checker_ext(char **text, int i, int j)
{
	if (text[j][i] == '-' || text[j][i] == '+')
	{
		if (ft_strlen(text[j]) == 1)
		{
			ft_free_str(text);
			return (0);
		}
		i++;
	}
	while (text[j][i])
	{
		if (!ft_isdigit(text[j][i])
			|| (text[j][i] >= 0 && text[j][i] <= 32))
		{
			ft_free_str(text);
			return (0);
		}
		i++;
	}
	return (1);
}

/*
To check the str with they're considered to be valid or not. It will split
the strings if they have ' '. After splitting it will get the size 
of each strings arrays
*/
static int	ft_str_checker(char *str)
{
	int		i;
	int		j;
	int		size;
	char	**text;

	j = 0;
	size = 0;
	text = ft_split(str, ' ');
	while (text[size])
		size++;
	while (text[j] != NULL)
	{
		i = 0;
		if (!str_checker_ext(text, i, j))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		j++;
	}
	ft_free_str(text);
	return (size);
}

/*
To check the value of the input whether it considers to be valid or not.
if it returns 0 it will end the program. If it returns other values it
return the size of the string.
*/
int	ft_valid_input(char *str)
{
	int		errno;

	errno = 0;
	errno = ft_str_checker(str);
	return (errno);
}

/*
Very similar to ft_atoi. The difference it is that it converts the string
into a long. This is so that later it can check if the string reaches the
int limit.
*/
long	ft_along(const char *str)
{
	long		res;
	int			sign;
	int			i;
	char		*pstr;

	res = 0;
	sign = 1;
	i = 0;
	pstr = (char *)str;
	while (pstr[i] == 32 || (pstr[i] >= 9 && pstr[i] <= 13))
		i++;
	if (pstr[i] == '-' || pstr[i] == '+')
	{
		if (pstr[i] == '-')
			sign = -(sign);
		i++;
	}
	while (pstr[i] >= '0' && pstr[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}
