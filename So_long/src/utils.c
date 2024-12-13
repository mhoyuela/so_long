/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyuela <mhoyuela@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-09 17:39:03 by mhoyuela          #+#    #+#             */
/*   Updated: 2024-12-09 17:39:03 by mhoyuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_strlen_sl(char *s)
{
	int i;

	i = 0;
	if(!s)
		return(0);
	while(s[i] && s[i] != '\n')
		i++;
	return(i);
}

void check_one(char *str)
{
	int i;

	i = 0;

	while(str[i] == '1')
		i++;
	if (str[i] == '\0' || str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
		return ;
	else
		ft_printerrors("Incorrect characters\n");
}

void	flood_fill(t_game *game, int y, int x)
{
	if (y < 0 || y >= game->width || x < 0 || x >= game->height || game->map_copy[x][y] == '1')
		return ;
	game->map_copy[x][y] = '1';
	flood_fill(game, y - 1, x);
	flood_fill(game, y + 1, x);
	flood_fill(game, y, x - 1);
	flood_fill(game, y, x + 1);

}

void	valid_flood_fill(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map_copy[y])
	{
		x = 0;
		while (game->map_copy[y][x])
		{
			if (((game->map_copy[y][x] == 'P') || (game->map_copy[y][x] == 'C') || (game->map_copy[y][x] == 'E')))
				ft_printerrors("Invalid map construction");
			x++;
		}
		y++;
	}
	//printmap(game->map_copy);
}

void	printmap(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			write (1, &map[y][x], 1);
			x++;
		}
		y++;
	}
	write (1, "\n", 1);
}
