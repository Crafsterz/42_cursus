/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:17:12 by mukhairu          #+#    #+#             */
/*   Updated: 2023/05/19 12:56:39 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*To check if the stack_a are properly sorted*/
int	sorted(t_list **stack_a)
{
	t_list	*check1;
	t_list	*check2;

	check1 = *stack_a;
	while (check1)
	{
		check2 = check1->next;
		while (check2)
		{
			if (*(int *)check1->content > *(int *)check2->content)
				return (0);
			check2 = check2->next;
		}
		check1 = check1->next;
	}
	return (1);
}

/*
To get the smallest value to be added to stack_b. If the value is less than
or equals to to it will push to stack_b. It will also rotate the stack_b 
if the value of the node is not sorted. if it is not it will sb.
*/
static void	get_smallest(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	while (size)
	{
		if (*(int *)(*stack_a)->content == 1 ||
			*(int *)(*stack_a)->content == 2)
			ft_pb(stack_b, stack_a);
		else
			ft_ra(stack_a);
		size--;
	}
	if (((*stack_b)->next) == NULL || *stack_b == NULL)
		return ;
	if (*(int *)((*stack_b)->content) < *(int *)((*stack_b)->next->content))
		ft_sb(stack_b);
}

//to sort if the stacks are equals to 2.
void	sort_2(t_list **stack_a)
{
	if (sorted(stack_a))
		return ;
	if (*(int *)((*stack_a)->content) > *(int *)((*stack_a)->next->content))
		ft_sa(stack_a);
}

//To sort with 3 values in the stack. 
void	sort_3(t_list **stack_a)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = *(int *)((*stack_a)->content);
	num2 = *(int *)((*stack_a)->next->content);
	num3 = *(int *)((*stack_a)->next->next->content);
	if ((num1 > num2 && num1 < num3) && (num2 < num3))
		ft_sa(stack_a);
	else if ((num1 > num2 && num1 > num3) && (num2 > num3))
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if ((num1 > num2 && num1 > num3) && (num2 < num3))
		ft_ra(stack_a);
	else if ((num1 < num2 && num2 > num3) && (num1 < num3))
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else if ((num1 < num2 && num1 > num3) && (num2 > num3))
		ft_rra(stack_a);
}

//To sort 5 values or less in the stack.
void	sort_5(t_list **stack_a, t_list **stack_b)
{
	get_smallest(stack_a, stack_b);
	sort_3(stack_a);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}
