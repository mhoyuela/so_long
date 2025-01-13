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
	char			**map;
	char			**map_copy;
	char			*name_map;
	int				player;
	int				collect;
	int				exit;
	int				height;
	int				width;
	int				x;
	int				y;
	int				count;
	int				moves;
	mlx_t			*init;
	mlx_image_t		*img_collect;
	mlx_image_t		*img_p;
	mlx_image_t		*img_exit;
	mlx_image_t		*img_f;
	mlx_image_t		*img_wall;
	mlx_texture_t	*texture;

}	t_g;

//map things
void	ft_init_struct(t_g *g);
void	map_staff(t_g *g, char *param, int i);
void	save_player_pos(t_g *g);
char	**make_matrix(char *path, t_g *g, int i);
int		c_l(char *path, t_g *g);

//errors
void	ft_printerrors(char *str, char **map, char **map_copy);
void	ft_error_free(char *msg, t_g *g);
char	**ft_free_map(char **map);

//map check
void	valid_format(char *map_name, t_g *map);
int		map_characther(t_g *map);
void	check_content(t_g *g);
int		ft_strlen_sl(char *s);
int		check_map_line(t_g *map, int i);

//utils
void	valid_flood_fill(t_g *g);
int		ft_strlen_sl(char *s);
void	check_one(char *str, t_g *g);
void	flood_fill(t_g *g, int y, int x);
void	printmap(char **map);

//utils2
void	create_line(char **matrix, char *line_in_matrix, int fd);
int		if_not_fd(int fd);

//textures
void	init_mlx_g(t_g *g);
void	put_textures(t_g *g);
void	set_textures(t_g *g);
void	put_floor(t_g *g);

//moves
void	close_window(t_g *g);
void	set_moves(mlx_key_data_t key, void *param);
int		do_moves(t_g *g, int move);

//mov
void	move_up(t_g *g);
void	move_down(t_g *g);
void	move_left(t_g *g);
void	move_right(t_g *g);
#endif