/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:29:40 by mukhairu          #+#    #+#             */
/*   Updated: 2023/05/19 12:29:44 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
To sort the location of each index values without changing the original stack.
It stores the data in an array to create to later use the data of the index 
locations
*/
static int	*index_sort(int *list_a, int num_elem)
{
	int	i;
	int	j;
	int	temp;
	int	*value;

	i = -1;
	value = ft_calloc(num_elem, sizeof(int));
	while (++i < num_elem)
		value[i] = list_a[i];
	i = 1;
	while (i < num_elem)
	{
		j = i;
		while (j > 0 && value[j - 1] > value[j])
		{
			temp = value[j];
			value[j] = value[j - 1];
			value[j - 1] = temp;
			j--;
		}
		i++;
	}
	return (value);
}

/*
The idea of get_index is to ensure if the value of the index are to be a 
duplicate or not. If it finds a duplicate, it will return a (-1). This
will show that the program to end.
*/
static int	get_index(int *list_a, int len, int n)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		if (list_a[i] == n)
			return (i);
	}
	return (-1);
}

/*
To get the the index value for each integer. It will also check the index to be 
a duplicate. If the value of the index to be a duplicate it will end the program.
*/
int	*ft_index(int *list_a, int num_elem)
{
	int	i;
	int	*value;
	int	*index_list;

	i = 0;
	value = ft_calloc(num_elem, sizeof(int));
	index_list = index_sort(list_a, num_elem);
	while (i < num_elem)
	{
		value[get_index(list_a, num_elem, index_list[i])] = i + 1;
		if (i + 1 < num_elem && index_list[i] == index_list[i + 1])
		{
			free(value);
			value = 0;
			break ;
		}
		i++;
	}
	free(list_a);
	free(index_list);
	return (value);
}
