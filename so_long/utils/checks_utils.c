/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:48:34 by mukhairu          #+#    #+#             */
/*   Updated: 2023/06/26 16:54:24 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*To check the value of the valid and invalid variable in the map. It is set 
the default value of item variable*/
static void	check_item_var(t_game *game)
{
	game->items_var.coll_num = 0;
	game->items_var.enem_num = 0;
	game->items_var.exit_num = 0;
	game->items_var.play_num = 0;
	game->items_var.othe_num = 0;
}

/*To update the item variable when it checks the variable items that 
are in the map*/
static void	item_update(t_game *game, char c)
{
	if (c == 'C')
		game->items_var.coll_num++;
	else if (c == 'P')
		game->items_var.play_num++;
	else if (c == 'E')
		game->items_var.exit_num++;
	else if (c == '2')
		game->items_var.enem_num++;
	else if (c == '1' || c == '0')
		return ;
	else
		game->items_var.othe_num++;
}

/*To check the item variable in the game. 
If the item variable that is not 0, 1, 2, C, E, or P, it will 
declare an error on the map*/
int	check_item(t_game *game)
{
	int	x;
	int	y;

	check_item_var(game);
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
			item_update(game, game->map[y][x]);
	}
	if (game->items_var.othe_num > 0)
		print_error("Invalid character detected!\n", game->map);
	else if (!(game->items_var.coll_num > 0 && game->items_var.exit_num == 1
			&& game->items_var.play_num == 1))
		print_error("Missing or duplicate character in the map!\n", game->map);
	return (1);
}
