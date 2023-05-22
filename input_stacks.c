/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:59:44 by mukhairu          #+#    #+#             */
/*   Updated: 2023/05/19 12:43:06 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
To put the input inside the created stacks. With every new input that are 
added it is added at the back of the stack. 
*/
void	ft_input_stacks(int input, t_list **stack_a)
{
	t_list	*node;
	int		*val;

	val = ft_calloc(1, sizeof(int));
	*val = input;
	node = ft_lstnew(val);
	ft_lstadd_back(stack_a, node);
}
