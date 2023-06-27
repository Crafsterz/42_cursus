/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:57:37 by mukhairu          #+#    #+#             */
/*   Updated: 2023/06/26 18:19:20 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Sets the animations for each sprites. For example for the player
static void	set_animation_sprites(t_game *game)
{
	int	x;
	int	y;

	game->animation.enem1le = mlx_xpm_file_to_image(game->mlx,
			"32bit_sprites/enemy1le.xpm", &x, &y);
	game->animation.enem2le = mlx_xpm_file_to_image(game->mlx,
			"32bit_sprites/enemy2le.xpm", &x, &y);
	game->animation.enem1ri = mlx_xpm_file_to_image(game->mlx,
			"32bit_sprites/enemy1ri.xpm", &x, &y);
	game->animation.enem2ri = mlx_xpm_file_to_image(game->mlx,
			"32bit_sprites/enemy2ri.xpm", &x, &y);
	game->animation.exit_close = mlx_xpm_file_to_image(game->mlx,
			"32bit_sprites/exitclose.xpm", &x, &y);
	game->animation.exit_open = mlx_xpm_file_to_image(game->mlx,
			"32bit_sprites/exitopen.xpm", &x, &y);
	game->animation.player1le = mlx_xpm_file_to_image(game->mlx,
			"32bit_sprites/player1le.xpm", &x, &y);
	game->animation.player2le = mlx_xpm_file_to_image(game->mlx,
			"32bit_sprites/player2le.xpm", &x, &y);
	game->animation.player1ri = mlx_xpm_file_to_image(game->mlx,
			"32bit_sprites/player1ri.xpm", &x, &y);
	game->animation.player2ri = mlx_xpm_file_to_image(game->mlx,
			"32bit_sprites/player2ri.xpm", &x, &y);
}

//Need to set the sprites later for the Player, Enemy and Exit
void	set_sprites(t_game *game)
{
	int	x;
	int	y;

	game->sprites.collect = mlx_xpm_file_to_image(game->mlx,
			"32bit_sprites/collect.xpm", &x, &y);
	game->sprites.wall = mlx_xpm_file_to_image(game->mlx,
			"32bit_sprites/wall.xpm", &x, &y);
	game->sprites.grass = mlx_xpm_file_to_image(game->mlx,
			"32bit_sprites/grass.xpm", &x, &y);
	set_animation_sprites(game);
	game->sprites.exit = game->animation.exit_close;
	game->sprites.player = game->animation.player1le;
	game->sprites.enemy = game->animation.enem1le;
}

/*To declare the sprites in the game. I.e, 1 is for sprites.wall*/
static void	put_sprites(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx,
			game->win, game->sprites.wall, x * 35, y * 35);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx,
			game->win, game->sprites.grass, x * 35, y * 35);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx,
			game->win, game->sprites.player, x * 35, y * 35);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx,
			game->win, game->sprites.collect, x * 35, y * 35);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx,
			game->win, game->sprites.exit, x * 35, y * 35);
	else if (game->map[y][x] == '2')
		mlx_put_image_to_window(game->mlx,
			game->win, game->sprites.enemy, x * 35, y * 35);
}

/*The function to set the animation for each sprite. It checks if the 
sprite is that particular sprite. It will set to another one based on
the frame_count.*/
int	animation(t_game *game)
{
	game->frame_count++;
	if (game->frame_count == 5000)
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->sprites.player == game->animation.player1le)
			game->sprites.player = game->animation.player2le;
		else if (game->sprites.player == game->animation.player2le)
			game->sprites.player = game->animation.player1le;
		else if (game->sprites.player == game->animation.player1ri)
			game->sprites.player = game->animation.player2ri;
		else if (game->sprites.player == game->animation.player2ri)
			game->sprites.player = game->animation.player1ri;
		if (game->sprites.enemy == game->animation.enem1le)
			game->sprites.enemy = game->animation.enem2le;
		else if (game->sprites.enemy == game->animation.enem2le)
			game->sprites.enemy = game->animation.enem1le;
		else if (game->sprites.enemy == game->animation.enem1ri)
			game->sprites.enemy = game->animation.enem2ri;
		else if (game->sprites.enemy == game->animation.enem2ri)
			game->sprites.enemy = game->animation.enem1ri;
		game->frame_count = 0;
		render(game->map, game);
	}
	return (0);
}

/*To render the game based on the declared sprites and the map location*/
void	render(char **map, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (map [y])
	{
		x = 0;
		while (map[y][x])
		{
			put_sprites(game, x, y);
			x++;
		}
		y++;
	}
	print_steps(game);
}
