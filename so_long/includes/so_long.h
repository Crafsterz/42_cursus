/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhairu <mukhairu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:12:40 by mukhairu          #+#    #+#             */
/*   Updated: 2023/06/25 15:34:35 by mukhairu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"

# define BUFFER_SIZE 1024

// Sprites // NEED TO ADD THE ANIMATION SPRITES!
typedef struct s_sprites
{
	void	*player;
	void	*enemy;
	void	*exit;
	void	*grass;
	void	*wall;
	void	*collect;
}			t_sprites;

//Animation structs for player, enemies and exit
typedef struct s_ani
{
	void	*player1le;
	void	*player2le;
	void	*player1ri;
	void	*player2ri;
	void	*enem1le;
	void	*enem2le;
	void	*enem1ri;
	void	*enem2ri;
	void	*exit_open;
	void	*exit_close;
}			t_ani;

//Items chars in the map
typedef struct s_items
{
	int	coll_num;
	int	enem_num;
	int	exit_num;
	int	play_num;
	int	othe_num;
}		t_items;

// Map
typedef struct s_map
{
	int	x;
	int	y;
}		t_map;

// Game
typedef struct s_game
{
	char		**map;
	void		*mlx;
	void		*win;
	t_map		size;
	t_sprites	sprites;
	t_ani		animation;
	int			steps;
	t_items		items_var;
	t_map		loc;
	int			frame_count;
}				t_game;

char	*get_next_line(int fd);
char	*ft_free(char *text, char *buffer);
void	print_win(char **map);
void	print_lose(char **map);
void	print_steps(t_game *game);
void	print_steps_term(int *steps);
void	print_error(char *err, char **map);
void	free_map(char **map);
// void	free_tiles(char *ret, int x);
// void	cpy_map(t_game *game, char **dup_map);

//Check Util
int		mapsize(t_game *game);
int		check(t_game *game, char **argv);
int		check_item(t_game *game);
int		flood_fill(char **map, t_game *game);

//Checking the map / game
char	**map_parse(char *map);

// Render the game
void	set_sprites(t_game *game);
void	render(char **map, t_game *game);
int		animation(t_game *game);

//move player
void	play_loc(t_game *game);
int		moveup(t_game *game);
int		movedown(t_game *game);
int		moveleft(t_game *game);
int		moveright(t_game *game);

#endif