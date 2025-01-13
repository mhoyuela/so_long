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

void	close_window(t_g *g)
{
	mlx_close_window(g->init);
}

void	set_moves(mlx_key_data_t key, void *param)
{
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		close_window((t_g *) param);
	if (key.key == MLX_KEY_UP && key.action == MLX_PRESS)
		move_up((t_g *) param);
	if (key.key == MLX_KEY_DOWN && key.action == MLX_PRESS)
		move_down((t_g *) param);
	if (key.key == MLX_KEY_RIGHT && key.action == MLX_PRESS)
		move_right((t_g *) param);
	if (key.key == MLX_KEY_LEFT && key.action == MLX_PRESS)
		move_left((t_g *) param);
}

int	do_moves(t_g *g, int move)
{
	if (move == 1 && g->map[g->y - 1][g->x] != '1')
	{
		g->y--;
		g->img_p->instances[0].y -= PIXEL;
		return (1);
	}
	if (move == 2 && g->map[g->y + 1][g->x] != '1')
	{
		g->y++;
		g->img_p->instances[0].y += PIXEL;
		return (1);
	}
	if (move == 3 && g->map[g->y][g->x + 1] != '1')
	{
		g->x++;
		g->img_p->instances[0].x += PIXEL;
		return (1);
	}
	if (move == 4 && g->map[g->y][g->x - 1] != '1')
	{
		g->x--;
		g->img_p->instances[0].x -= PIXEL;
		return (1);
	}
	return (0);
}
