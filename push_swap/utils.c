/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:04:16 by mukhairu          #+#    #+#             */
/*   Updated: 2023/05/19 13:02:50 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
To print the stacks that were created. To make a visualization of the stacks
*/
void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	ft_printf("stack_a\t stack_b\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			ft_printf("%i\t", *(int *)stack_a->content);
			stack_a = stack_a->next;
		}
		else
			ft_printf("\t");
		if (stack_b)
		{
			ft_printf("%i\t", *(int *)stack_b->content);
			stack_b = stack_b->next;
		}
		ft_printf("\n");
	}
}

/*
The function to get the str. It will join the string if there are any spaces.
*/
char	*ft_get_str(int argc, char **argv)
{
	int		i;
	char	*str;
	char	*jn1;

	i = 1;
	str = ft_strdup(argv[1]);
	while (i < argc - 1)
	{
		jn1 = ft_strjoin(str, " ");
		free(str);
		str = ft_strjoin(jn1, argv[i + 1]);
		free(jn1);
		i++;
	}
	return (str);
}

/*
A function to to free an array of strings.
*/
void	ft_free_str(char **str)
{
	char	**temp;
	int		i;

	i = 0;
	temp = str;
	while (str[i] != NULL)
		free(str[i++]);
	free(temp);
}

/*
To free all the stack nodes and memory after being used. The node are the
to be freed.
*/
void	free_stack(t_list *node)
{
	t_list	*temp;

	temp = NULL;
	while (temp)
	{
		temp = node;
		temp = temp -> next;
		free(temp -> content);
		free(temp);
	}
}
