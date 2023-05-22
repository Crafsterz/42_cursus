/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:03:01 by mukhairu          #+#    #+#             */
/*   Updated: 2023/05/11 18:21:40 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*The main swap function.*/
static void	ft_swap(t_list **node)
{
	t_list	*temp;

	if (*node == NULL || (*node)->next == NULL)
		return ;
	temp = (*node)->next;
	(*node)->next = temp->next;
	temp->next = *node;
	*node = temp;
}

//Swap in stack_a
void	ft_sa(t_list **stack_a)
{
	ft_swap(stack_a);
	ft_printf("sa\n");
}

//Swap in stack_b
void	ft_sb(t_list **stack_b)
{
	ft_swap(stack_b);
	ft_printf("sb\n");
}

//Swap both stack_a and stack_b
void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_printf("ss\n");
}
