/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:35:21 by mukhairu          #+#    #+#             */
/*   Updated: 2023/05/11 17:32:28 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Almost similar to as the start of sort. This function will check if the 
bits are 1 it pa, else rotate in stack_b.*/
static void	optimise_radix(t_list **stack_a, t_list **stack_b, int bit)
{
	int	size;
	int	i;

	i = -1;
	size = ft_lstsize(*stack_b);
	while (++i < size)
	{
		if ((*(int *)(*stack_b)->content >> bit) & 1)
			ft_pa(stack_a, stack_b);
		else
			ft_rb(stack_b);
	}
}

/*Main Radix sort algorigthm written. It is sorted by using 
the value of the bits. It begins checking the value of the stacks whether 
it is a 0's or 1's. If the value is a 0 it will pb, else rotate.*/
void	ft_radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	bit;
	int	i;
	int	size;

	bit = -1;
	while (!sorted(stack_a))
	{
		i = -1;
		++bit;
		size = ft_lstsize(*stack_a);
		while (++i < size)
		{
			if ((*(int *)(*stack_a)->content >> bit) & 1)
				ft_ra(stack_a);
			else
				ft_pb(stack_b, stack_a);
		}
		optimise_radix(stack_a, stack_b, bit + 1);
	}
	while (*stack_b)
		ft_pa(stack_a, stack_b);
}
