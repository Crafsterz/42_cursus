/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:03:18 by mukhairu          #+#    #+#             */
/*   Updated: 2023/06/26 18:09:43 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Finding and setting the location of the player
void	play_loc(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y++])
	{
		x = 0;
		while (game->map[y][x++])
		{
			if (game->map[y][x] == 'P')
			{
				game->loc.y = y;
				game->loc.x = x;
				return ;
			}
		}
	}
}

//Player to move up
int	moveup(t_game *game)
{
	play_loc(game);
	if (game->map[game->loc.y - 1][game->loc.x] == '1')
		return (0);
	if (game->map[game->loc.y - 1][game->loc.x] == '2')
		print_lose(game->map);
	if (game->map[game->loc.y - 1][game->loc.x] == 'C')
		game->items_var.coll_num--;
	if (game->map[game->loc.y - 1][game->loc.x] == 'E'
		&& game->items_var.coll_num > 0)
		return (0);
	if (game->map[game->loc.y - 1][game->loc.x] == 'E'
		&& game->items_var.coll_num == 0)
		print_win(game->map);
	game->map[game->loc.y][game->loc.x] = '0';
	game->map[game->loc.y - 1][game->loc.x] = 'P';
	if (game->items_var.coll_num == 0)
		game->sprites.exit = game->animation.exit_open;
	game->steps++;
	mlx_clear_window(game->mlx, game->win);
	render(game->map, game);
	print_steps_term(&game->steps);
	return (0);
}

//Player to move down
int	movedown(t_game *game)
{
	play_loc(game);
	if (game->map[game->loc.y + 1][game->loc.x] == '1')
		return (0);
	if (game->map[game->loc.y + 1][game->loc.x] == '2')
		print_lose(game->map);
	if (game->map[game->loc.y + 1][game->loc.x] == 'C')
		game->items_var.coll_num--;
	if (game->map[game->loc.y + 1][game->loc.x] == 'E'
		&& game->items_var.coll_num > 0)
		return (0);
	if (game->map[game->loc.y + 1][game->loc.x] == 'E'
		&& game->items_var.coll_num == 0)
		print_win(game->map);
	game->map[game->loc.y][game->loc.x] = '0';
	game->map[game->loc.y + 1][game->loc.x] = 'P';
	if (game->items_var.coll_num == 0)
		game->sprites.exit = game->animation.exit_open;
	game->steps++;
	mlx_clear_window(game->mlx, game->win);
	render(game->map, game);
	print_steps_term(&game->steps);
	return (0);
}

//Player to move left
int	moveleft(t_game *game)
{
	play_loc(game);
	if (game->map[game->loc.y][game->loc.x - 1] == '1')
		return (0);
	if (game->map[game->loc.y][game->loc.x - 1] == '2')
		print_lose(game->map);
	if (game->map[game->loc.y][game->loc.x - 1] == 'C')
		game->items_var.coll_num--;
	if (game->map[game->loc.y][game->loc.x - 1] == 'E'
		&& game->items_var.coll_num > 0)
		return (0);
	if (game->map[game->loc.y][game->loc.x - 1] == 'E'
		&& game->items_var.coll_num == 0)
		print_win(game->map);
	game->map[game->loc.y][game->loc.x] = '0';
	game->map[game->loc.y][game->loc.x - 1] = 'P';
	if (game->items_var.coll_num == 0)
		game->sprites.exit = game->animation.exit_open;
	game->sprites.player = game->animation.player1le;
	game->steps++;
	mlx_clear_window(game->mlx, game->win);
	render(game->map, game);
	print_steps_term(&game->steps);
	return (0);
}

//Player to move right
int	moveright(t_game *game)
{
	play_loc(game);
	if (game->map[game->loc.y][game->loc.x + 1] == '1')
		return (0);
	if (game->map[game->loc.y][game->loc.x + 1] == '2')
		print_lose(game->map);
	if (game->map[game->loc.y][game->loc.x + 1] == 'C')
		game->items_var.coll_num--;
	if (game->map[game->loc.y][game->loc.x + 1] == 'E'
		&& game->items_var.coll_num > 0)
		return (0);
	if (game->map[game->loc.y][game->loc.x + 1] == 'E'
		&& game->items_var.coll_num == 0)
		print_win(game->map);
	game->map[game->loc.y][game->loc.x] = '0';
	game->map[game->loc.y][game->loc.x + 1] = 'P';
	if (game->items_var.coll_num == 0)
		game->sprites.exit = game->animation.exit_open;
	game->sprites.player = game->animation.player1ri;
	game->steps++;
	mlx_clear_window(game->mlx, game->win);
	render(game->map, game);
	print_steps_term(&game->steps);
	return (0);
}
