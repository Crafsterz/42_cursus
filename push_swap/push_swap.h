/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:00:43 by mukhairu          #+#    #+#             */
/*   Updated: 2023/05/18 19:21:32 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"
# include "ft_printf/libftprintf.h"

//Struct of Linked List
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

//utilities
void	print_stacks(t_list *stack_a, t_list *stack_b);
void	free_stack(t_list *node);
int		sorted(t_list **stack_a);
char	*ft_get_str(int argc, char **argv);
void	ft_free_str(char **str);

//from input_stacks
int		ft_input(int size, char *str, t_list **stack_a);
void	ft_input_stacks(int input, t_list **stack_a);

// input checker
int		ft_valid_input(char *str);
long	ft_along(const char *str);
void	ft_replace_char(char *str, char old, char new);

//index
int		*ft_index(int *list_a, int num_elem);

//swap node sa, sb, ss
void	ft_sa(t_list **stack_a);
void	ft_sb(t_list **stack_b);
void	ft_ss(t_list **stack_a, t_list **stack_b);

//push node pa, pb
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_b, t_list **stack_a);

//rotate node ra, rb, rra, rrb
void	ft_rotate(t_list **node, int n);
void	ft_ra(t_list **stack_a);
void	ft_rb(t_list **stack_b);
void	ft_rra(t_list **stack_a);
void	ft_rrb(t_list **stack_b);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rrr(t_list **stack_a, t_list **stack_b);

//Algorithm
//small sort
void	sort_2(t_list **stack_a);
void	sort_3(t_list **stack_a);
void	sort_5(t_list **stack_a, t_list **stack_b);
void	ft_radix_sort(t_list **stack_a, t_list **stack_b);

#endif
