/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:11:19 by mukhairu          #+#    #+#             */
/*   Updated: 2023/05/19 12:47:34 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
The calling function to for the stacks to be sorted
*/
int	sort_stacks(t_list *stack_a, t_list *stack_b)
{
	if (sorted(&stack_a))
		return (0);
	else if (ft_lstsize(stack_a) == 2)
		sort_2(&stack_a);
	else if (ft_lstsize(stack_a) == 3)
		sort_3(&stack_a);
	else if (ft_lstsize(stack_a) <= 5)
		sort_5(&stack_a, &stack_b);
	else if (ft_lstsize(stack_a) > 5)
		ft_radix_sort(&stack_a, &stack_b);
	return (1);
}

/*
To get the index values for their respective node stack. 
*/
void	index_value(int *num_list, t_list *head)
{
	int		i;

	i = 0;
	while (head)
	{
		*(int *)head->content = num_list[i];
		head = head->next;
		i++;
	}
}

/*
To create a listing and index of the stacks. The indexes are to make easy
calculation for sorting as well as checking for any duplicate errors in the
stacks
*/
int	ft_listing(int size, t_list *stack_a)
{
	int		i;
	int		*num_list;
	t_list	*head;

	head = stack_a;
	i = 0;
	num_list = ft_calloc(size, sizeof(int));
	while (++i <= size)
	{
		num_list[i - 1] = *(int *)stack_a->content;
		if (stack_a->next == NULL)
			break ;
		stack_a = stack_a->next;
	}
	num_list = ft_index(num_list, size);
	i = 0;
	if (!num_list)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	index_value(num_list, head);
	free(num_list);
	return (1);
}

/*
input function that adds the input in the starting stacks.
Need to remove the print in this function
*/
int	ft_input(int size, char *str, t_list **stack_a)
{
	int		i;
	long	along;
	char	**text;

	i = -1;
	text = ft_split(str, ' ');
	while (++i < size)
	{
		along = ft_along(text[i]);
		if (along < INT_MIN || along > INT_MAX)
		{
			ft_putstr_fd("Error\n", 2);
			ft_free_str(text);
			return (0);
		}
		ft_input_stacks(along, stack_a);
	}
	ft_free_str(text);
	return (1);
}

/*
The begining of the entire program. It uses a linked list data structure.
*/
int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;
	char	*str;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		str = ft_get_str(argc, argv);
		size = ft_valid_input(str);
		if (size == 0)
			return (0);
		if (!ft_input(size, str, &stack_a))
			return (0);
		if (!ft_listing(size, stack_a))
			return (0);
		if (!sort_stacks(stack_a, stack_b))
			return (0);
		free(str);
		free_stack(stack_a);
		free_stack(stack_b);
	}
	return (0);
}
// system("leaks push_swap");
// t_list *tmp_a = stack_a;
// 		t_list *tmp_b = stack_b;
// 		while (tmp_a != NULL)
// 		{
// 			ft_printf("test = %d\n", *(int *)tmp_a->content);
// 			tmp_a = tmp_a->next;
// 		}
