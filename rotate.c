/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:53:56 by mukhairu          #+#    #+#             */
/*   Updated: 2023/05/19 12:53:07 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
The main function that rotates the function for their respective stacks. The 
int n indicates whether the stack need to be rotated or not. If the value is
0 is rotate 1 stack up. If the value of n is 1 it will reverse rotate all 
the elements down.
*/
void	ft_rotate(t_list **node, int n)
{
	t_list	*temp;
	t_list	*item;

	if (!*node)
		return ;
	if (n == 0)
	{
		temp = *node;
		(void)item;
		(*node) = (*node)->next;
		temp->next = NULL;
		ft_lstadd_back(node, temp);
	}
	else
	{
		if ((*node)->next == NULL)
			return ;
		item = ft_lstlast(*node);
		temp = *node;
		while (temp->next != item)
			temp = temp->next;
		temp->next = NULL;
		ft_lstadd_front(node, item);
	}
}

//Rotate all the elements by 1 in stack a. 1st element becomes last 
void	ft_ra(t_list **stack_a)
{
	ft_rotate(stack_a, 0);
	ft_printf("ra\n");
}

//Rotate all the elements up by 1 in stack b. 1st element becomes last
void	ft_rb(t_list **stack_b)
{
	ft_rotate(stack_b, 0);
	ft_printf("rb\n");
}

//Rotate all the elements down by 1 in stack a. 1st element becomes first
void	ft_rra(t_list **stack_a)
{
	ft_rotate(stack_a, 1);
	ft_printf("rra\n");
}

//Rotate all the elements down by 1 in stack b. 1st element becomes first
void	ft_rrb(t_list **stack_b)
{
	ft_rotate(stack_b, 1);
	ft_printf("rrb\n");
}
