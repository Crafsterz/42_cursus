/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnrl_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:08:36 by mukhairu          #+#    #+#             */
/*   Updated: 2023/06/26 18:22:50 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Print win text
void	print_win(char **map)
{
	ft_putstr_fd("YOU WIN!\n", 1);
	free_map(map);
	exit (0);
}
// system("leaks -q so_long"); add after free to test

//Print the lose text
void	print_lose(char **map)
{
	ft_putstr_fd("YOU LOSE!\n", 1);
	free_map(map);
	exit (0);
}
// system("leaks -q so_long"); add after free to test

//Prints the total steps that are on the screen of the game
void	print_steps(t_game *game)
{
	char	*num;
	char	*total;

	num = ft_itoa(game->steps);
	total = ft_strjoin("Steps: ", num);
	mlx_string_put(game->mlx, game->win, 10, 10, 0x000000, total);
	free(num);
	free(total);
}

//Prints the total steps that are in the terminal
void	print_steps_term(int *steps)
{
	ft_putstr_fd("Steps: ", 1);
	ft_putnbr_fd(*steps, 1);
	ft_putstr_fd("\n", 1);
}

//Prints the error text
void	print_error(char *err, char **map)
{
	ft_putstr_fd("Error! ", 2);
	ft_putstr_fd(err, 2);
	free_map(map);
	exit (1);
}
// system("leaks -q so_long"); add after free to test
