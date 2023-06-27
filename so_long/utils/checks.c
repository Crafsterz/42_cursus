/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:57:06 by mukhairu          #+#    #+#             */
/*   Updated: 2023/06/26 17:34:26 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*A check function to check the wall whether it is enclosed or not*/
int	check_wall(char **map)
{
	int	x;
	int	y;
	int	row;

	row = 0;
	y = 0;
	while (map[y])
	{
		if (!(map[y][0] == '1' && map[y][ft_strlen(*map) - 1] == '1'))
			return (0);
		y++;
	}
	x = 0;
	y--;
	while (x < (int)ft_strlen(*map))
	{
		if (!(map[0][x] == '1' && map[y][x] == '1'))
			return (0);
		x++;
	}
	return (1);
}

//To check the file type of the 
static int	check_file_type(t_game *game, char **argv)
{
	int	i;

	i = ft_strlen(argv[1]);
	i--;
	if (argv[1][i--] == 'r')
		if (argv[1][i--] == 'e')
			if (argv[1][i--] == 'b')
				return (1);
	print_error("File type wrong!\n", game->map);
	return (0);
}

/*The full list of all to check for any errors for the maps and the game. 
At the same time the data of the map is also saved for example the item 
variables that are in the maps are saved during the checking*/
int	check(t_game *game, char **argv)
{
	if (!check_file_type(game, argv))
		return (0);
	else if (!mapsize(game))
		return (0);
	else if (!check_item(game))
		return (0);
	else if (!check_wall(game->map))
		print_error("Invalid wall detected!\n", game->map);
	else if (!flood_fill(game->map, game))
		print_error("Invalid path!\n", game->map);
	return (1);
}
