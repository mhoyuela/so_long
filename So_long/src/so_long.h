/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyuela <mhoyuela@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-21 15:28:51 by mhoyuela          #+#    #+#             */
/*   Updated: 2024-11-21 15:28:51 by mhoyuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "unistd.h"
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "MLX42/include/MLX42/MLX42.h"
# define PIXEL 64

typedef struct s_long
{
	char	**map;
	char	**map_copy;
	char	*name_map;
	int		player;
	int		collect;
	int		exit;
	int		height;
	int		width;
	int		player_x;
	int		player_y;
	int		count;
	int		moves;
	mlx_t			*init;
	mlx_image_t		*img_collect;
	mlx_image_t		*img_player;
	mlx_image_t		*img_exit;
	mlx_image_t		*img_floor;
	mlx_image_t		*img_wall;
	mlx_texture_t	*texture;

} t_game;

//map things
void	ft_init_struct(t_game *game);
void	map_staff(t_game *game, char *param);
void	save_player_pos(t_game *game);
char	**make_matrix(char *path_to_file,t_game *game);
int		count_lines(char *path,t_game *game);

//errors
void	ft_printerrors(char *str);
void	ft_error_free(char *msg,t_game *game);

//map check
void	valid_format(char *map_name, t_game *map);
int		map_characther(t_game *map);
void	check_content(t_game *game);
int		ft_strlen_sl(char *s);

//utils
void	valid_flood_fill(t_game *game);
int		ft_strlen_sl(char *s);
void	check_one(char *str);
void	flood_fill(t_game *game, int y, int x);
void	printmap(char **map);

//textures
void	init_mlx_game(t_game *game);
void	put_textures(t_game *game);
void	set_textures(t_game *game);
void	put_floor(t_game *game);

//moves
void	close_window(t_game *game);
void	set_moves(mlx_key_data_t key, void *param);
int	do_moves(t_game *game, int move);

//mov
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);


#endif