/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:50:43 by mukhairu          #+#    #+#             */
/*   Updated: 2023/06/26 18:19:28 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//To free the map of that was allocated to prevent leaks
void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

//To check for fd if it exists or not
int	check_fd(int fd)
{
	if (fd < 0)
	{
		ft_putendl_fd("Error! File not found!", 2);
		exit (2);
	}
	return (1);
}

/*The main function that parses the map. This reads the text from the 
.ber file. It first checks if the file exists. If it does it will 
run the get_next_line function to read each text that are in the file. 
Once it is completed, it ft_splits array map based from '\n'*/
char	**map_parse(char *map)
{
	char	*line;
	char	*out;
	int		fd;
	char	**r;

	line = "";
	out = ft_strdup("");
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (line == NULL || line[0] == '\n')
			break ;
		out = ft_free(out, line);
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	r = ft_split(out, '\n');
	free(out);
	return (r);
}

/*It checks and sets the of map. If the is not rectangular it return as a 0, 
the game will not run because it is consider as an error. It also checks
whether the map has an extra line or not if it does, it return 0 as an error*/
int	mapsize(t_game *game)
{
	int	x;
	int	y;
	int	x_len;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
			x++;
		if (y != 0 && x_len != x)
			print_error("Extra line map!", game->map);
		x_len = x;
		y++;
	}
	if (y == x)
		print_error("Wrong map size, must be rectangular!\n", game->map);
	game->size.x = x * 35;
	game->size.y = y * 35;
	return (1);
}
