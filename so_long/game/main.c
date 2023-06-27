/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:59:44 by mukhairu          #+#    #+#             */
/*   Updated: 2023/06/26 18:36:18 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

/*
To destroy the window and free the map
*/
static int	dest_win(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_putstr_fd("Close window\n", 1);
	free_map(game->map);
	free(game->mlx);
	exit(0);
}
// system("leaks -q so_long"); add after free to test

/*
To set keypress action on the program. For now just testing
*/
static int	keypress(int code, t_game *game)
{
	if (code == 13 || code == 126)
		moveup(game);
	else if (code == 0 || code == 123)
		moveleft(game);
	else if (code == 1 || code == 125)
		movedown(game);
	else if (code == 2 || code == 124)
		moveright(game);
	else if (code == 53)
		dest_win(game);
	return (0);
}

//The main start of the program
int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game.map = map_parse(argv[1]);
		if (check(&game, argv) == 0)
			print_error("Issues was found!", game.map);
		game.steps = 0;
		game.frame_count = 0;
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, game.size.x,
				game.size.y, "so_long");
		set_sprites(&game);
		render(game.map, &game);
		mlx_key_hook(game.win, keypress, &game);
		mlx_hook(game.win, 17, (1L << 0), dest_win, &game);
		mlx_loop_hook(game.mlx, animation, &game);
		mlx_loop(game.mlx);
	}
	else
		ft_putendl_fd("Error! Too few or too many arguments!", 2);
	return (0);
}
	// system("leaks -q so_long"); add before return(0) to test
