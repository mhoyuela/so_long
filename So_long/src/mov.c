/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyuela <mhoyuela@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-13 17:23:21 by mhoyuela          #+#    #+#             */
/*   Updated: 2024-12-13 17:23:21 by mhoyuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	if (do_moves(game, 1) == 1)
	{
		if (game->map[game->player_y][game->player_x] == 'C')
		{
			game->count++;
			game->map[game->player_y][game->player_x] = '0';
			mlx_image_to_window(game->init, game->img_floor, game->player_x * PIXEL, game->player_y * PIXEL);
			mlx_delete_image(game->init, game->img_player);
			game->texture = mlx_load_png("image/player.png");
			if (!game->texture)
				ft_printerrors("loading player texture");
			game->img_player = mlx_texture_to_image(game->init, game->texture);
			mlx_image_to_window(game->init, game->img_player, game->player_x * PIXEL, game->player_y * PIXEL);
			mlx_delete_texture(game->texture);
		}
		else if (game->map[game->player_y][game->player_x] == 'E' && game->count == game->collect)
		{
			game->moves++;
			ft_printf("Moves: %d\n", game->moves);
			close_window(game);
		}
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
	}
}

void	move_down(t_game *game)
{
	if (do_moves(game, 2) == 1)
	{
		if (game->map[game->player_y][game->player_x] == 'C')
		{
			game->count++;
			game->map[game->player_y][game->player_x] = '0';
			mlx_image_to_window(game->init, game->img_floor, game->player_x * PIXEL, game->player_y * PIXEL);
			mlx_delete_image(game->init, game->img_player);
			game->texture = mlx_load_png("image/player.png");
			if (!game->texture)
				ft_printerrors("loading player texture");
			game->img_player = mlx_texture_to_image(game->init, game->texture);
			mlx_image_to_window(game->init, game->img_player, game->player_x * PIXEL, game->player_y * PIXEL);
			mlx_delete_texture(game->texture);
		}
		else if (game->map[game->player_y][game->player_x] == 'E' && game->count == game->collect)
		{
			game->moves++;
			ft_printf("Moves: %d\n", game->moves);
			close_window(game);
		}
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
	}
}

void	move_left(t_game *game)
{
	if (do_moves(game, 3) == 1)
	{
		if (game->map[game->player_y][game->player_x] == 'C')
		{
			game->count++;
			game->map[game->player_y][game->player_x] = '0';
			mlx_image_to_window(game->init, game->img_floor, game->player_x * PIXEL, game->player_y * PIXEL);
			mlx_delete_image(game->init, game->img_player);
			game->texture = mlx_load_png("image/player.png");
			if (!game->texture)
				ft_printerrors("loading player texture");
			game->img_player = mlx_texture_to_image(game->init, game->texture);
			mlx_image_to_window(game->init, game->img_player, game->player_x * PIXEL, game->player_y * PIXEL);
			mlx_delete_texture(game->texture);
		}
		else if (game->map[game->player_y][game->player_x] == 'E' && game->count == game->collect)
		{
			game->moves++;
			ft_printf("Moves: %d\n", game->moves);
			close_window(game);
		}
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
	}
}

void	move_right(t_game *game)
{
	if (do_moves(game, 4) == 1)
	{
		if (game->map[game->player_y][game->player_x] == 'C')
		{
			game->count++;
			game->map[game->player_y][game->player_x] = '0';
			mlx_image_to_window(game->init, game->img_floor, game->player_x * PIXEL, game->player_y * PIXEL);
			mlx_delete_image(game->init, game->img_player);
			game->texture = mlx_load_png("image/player.png");
			if (!game->texture)
				ft_printerrors("loading player texture");
			game->img_player = mlx_texture_to_image(game->init, game->texture);
			mlx_image_to_window(game->init, game->img_player, game->player_x * PIXEL, game->player_y * PIXEL);
			mlx_delete_texture(game->texture);
		}
		else if (game->map[game->player_y][game->player_x] == 'E' && game->count == game->collect)
		{
			game->moves++;
			ft_printf("Moves: %d\n", game->moves);
			close_window(game);
		}
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
	}
}