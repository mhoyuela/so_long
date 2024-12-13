/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyuela <mhoyuela@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-13 16:07:36 by mhoyuela          #+#    #+#             */
/*   Updated: 2024-12-13 16:07:36 by mhoyuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_window(t_game *game)
{
	mlx_close_window(game->init);
}
void	set_moves(mlx_key_data_t key, void *param)
{
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		close_window((t_game *) param);
	if (key.key == MLX_KEY_UP && key.action == MLX_PRESS)
		move_up((t_game *) param);
	if (key.key == MLX_KEY_DOWN && key.action == MLX_PRESS)
		move_down((t_game *) param);
	if (key.key == MLX_KEY_LEFT && key.action == MLX_PRESS)
		move_left((t_game *) param);
	if (key.key == MLX_KEY_RIGHT && key.action == MLX_PRESS)
		move_right((t_game *) param);
} 

int	do_moves(t_game *game, int move)
{
	if (move == 1 && game->map[game->player_y - 1][game->player_x] != '1')
	{
		game->player_y--;
		game->img_player->instances[0].y -= PIXEL;
	}
	if (move == 2 && game->map[game->player_y + 1][game->player_x] != '1')
	{
		game->player_y++;
		game->img_player->instances[0].y += PIXEL;
		return (1);
	}
	if (move == 3 && game->map[game->player_y][game->player_x + 1] != '1')
	{
		game->player_x++;
		game->img_player->instances[0].x += PIXEL;
		return (1);
	}
	if (move == 4 && game->map[game->player_y][game->player_x - 1] != '1')
	{
		game->player_x--;
		game->img_player->instances[0].x -= PIXEL;
		return (1);
	}
	return (0);
}