/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:09:03 by mukhairu          #+#    #+#             */
/*   Updated: 2023/06/26 17:54:40 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*To check the char that are in the map. If char are pasable char for the 
player to pass ot will add an 'F'. If E was detected, 
it will add coll->exit_num = 1 else it will return 0*/
static int	check_char(char c, t_items *coll)
{
	if (c == '0' || c == 'C')
		return (1);
	if (c == 'E')
		coll->exit_num = 1;
	return (0);
}

/*It enters the flood_fill algorithm function. It will check 
if the char is C or any valid char it will return as a 'F' to signify 
that the square on the map has been visited*/
static void	enter(char **map, t_map start, t_items *coll)
{
	if (map[start.y][start.x] == 'C')
		coll->coll_num++;
	map[start.y][start.x] = 'F';
}

/*The recursive function that befgins that the flood fill. It checks each 
square for any valid passible path using the check_char function*/
static void	run_fill(char **map, t_map start, t_items *coll)
{
	enter(map, start, coll);
	if (check_char(map[start.y + 1][start.x], coll))
	{
		start.y = start.y + 1;
		start.x = start.x;
		run_fill(map, start, coll);
	}
	if (check_char(map[start.y - 1][start.x], coll))
	{
		start.y = start.y - 1;
		start.x = start.x;
		run_fill(map, start, coll);
	}
	if (check_char(map[start.y][start.x + 1], coll))
	{
		start.y = start.y;
		start.x = start.x + 1;
		run_fill(map, start, coll);
	}
	if (check_char(map[start.y][start.x - 1], coll))
	{
		start.y = start.y;
		start.x = start.x - 1;
		run_fill(map, start, coll);
	}
}

/*The function creates a dupplicated array. This is to prevent for 
the original map array is not altered or lost*/
static char	**arrdup(char **map)
{
	char	**ret;
	int		i;

	i = 0;
	while (map[i])
		i++;
	ret = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (map[i])
	{
		ret[i] = ft_strdup(map[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

/*It checks player locations first to allow the flood fill algo to begin. 
Besides that, it duplicates a map array. This is to prevent original 
map array to be lost. Once it runs its recursive functions in run_fill function, 
it checks if the exit is available, the total collectable is equivalent to 
original map. If so, it will continues and returns 1.*/
int	flood_fill(char **map, t_game *game)
{
	t_items	coll;
	t_map	start;
	char	**mapcopy;

	coll.coll_num = 0;
	play_loc(game);
	start.x = game->loc.x;
	start.y = game->loc.y;
	mapcopy = arrdup(map);
	run_fill(mapcopy, start, &coll);
	if (coll.exit_num == 1 && coll.coll_num == game->items_var.coll_num)
	{
		free_map(mapcopy);
		return (1);
	}
	free_map(mapcopy);
	return (0);
}
