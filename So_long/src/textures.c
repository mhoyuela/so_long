/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyuela <mhoyuela@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-11 17:03:26 by mhoyuela          #+#    #+#             */
/*   Updated: 2024-12-11 17:03:26 by mhoyuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx_game(t_game *game)
{
	game->init = mlx_init((game->width -1) * PIXEL, (game->height) * PIXEL, "so_long", false);
	if (!game->init)
		ft_printerrors("inizializating mlx game");
	set_textures(game);
	put_textures(game);
	mlx_key_hook(game->init, &set_moves, game);
	mlx_loop(game->init);
}
void	set_textures(t_game *game)
{
	game->texture = mlx_load_png("images/player.png");
	if (!game->texture)
		ft_printerrors("failure creating texture\n");
	game->img_player = mlx_texture_to_image(game->init, game->texture);
	mlx_delete_texture(game->texture);
	game->texture = mlx_load_png("images/wall.png");
	if (!game->texture)
		ft_printerrors("failure creating texture\n");
	game->img_wall = mlx_texture_to_image(game->init, game->texture);
	mlx_delete_texture(game->texture);
	game->texture = mlx_load_png("images/floor.png");
	if (!game->texture)
		ft_printerrors("failure creating texture\n");
	game->img_floor = mlx_texture_to_image(game->init, game->texture);
	mlx_delete_texture(game->texture);
	game->texture = mlx_load_png("images/exit.png");
	if (!game->texture)
		ft_printerrors("failure creating texture\n");
	game->img_exit = mlx_texture_to_image(game->init, game->texture);
	mlx_delete_texture(game->texture);
	game->texture = mlx_load_png("images/exit.png");
	if (!game->texture)
		ft_printerrors("failure creating texture\n");
	game->img_exit = mlx_texture_to_image(game->init, game->texture);
	mlx_delete_texture(game->texture);
}

void	put_textures(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	put_floor(game);
	while (game->height > y)
	{
		x = 0;
		while (game->map[y][x] != '\0' && game->map[y][x] != '\n')
		{
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->init, game->img_wall,
					x * PIXEL, y * PIXEL);
			else if (game->map[y][x] == 'E')
				mlx_image_to_window(game->init, game->img_exit,
					x * PIXEL, y * PIXEL);
			else if (game->map[y][x] == 'C')
				mlx_image_to_window(game->init, game->img_collect,
					x * PIXEL, y * PIXEL);
			x++;
		}
		y++;
	}
	mlx_image_to_window(game->init, game->img_player,
					game->player_x * PIXEL, game->player_y * PIXEL);
}

void	put_floor(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->height > y)
	{
		x = 0;
		while (game->map[y][x] != '\0' && game->map[y][x] != '\n')
		{
			mlx_image_to_window(game->init, game->img_floor,
					x * PIXEL, y * PIXEL);
			x++;
		}
		y++;
	}
}