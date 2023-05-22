/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:29:19 by mukhairu          #+#    #+#             */
/*   Updated: 2023/05/11 17:20:26 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*To push the data their respective stacks
dest is the destination of the data to be sent.
src is the source of the data that it was originated from*/
static void	ft_push(t_list **dest, t_list **src)
{
	t_list	*temp;

	if (!*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = NULL;
	ft_lstadd_front(dest, temp);
}

//to push the top stack data from b into a 
void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_b)
		return ;
	ft_push(stack_a, stack_b);
	ft_printf("pa\n");
}

//to push the top stack data from a into b
void	ft_pb(t_list **stack_b, t_list **stack_a)
{
	if (!*stack_a)
		return ;
	ft_push(stack_b, stack_a);
	ft_printf("pb\n");
}
