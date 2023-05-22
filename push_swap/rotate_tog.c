/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_tog.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:08:15 by mukhairu          #+#    #+#             */
/*   Updated: 2023/04/11 19:11:28 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Rotate both stack a and stack b by 1 element up.
void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a, 0);
	ft_rotate(stack_b, 0);
	ft_printf("rr\n");
}

//Rotate both stack a and b by 1 element down.
void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a, 1);
	ft_rotate(stack_b, 1);
	ft_printf("rrr\n");
}
