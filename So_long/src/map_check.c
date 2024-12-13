/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyuela <mhoyuela@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-26 16:00:35 by mhoyuela          #+#    #+#             */
/*   Updated: 2024-09-26 16:00:35 by mhoyuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_characther(t_game *map)
{
	int	i;
	int	j;

	i = 0;
	check_one(map->map[i]);
	check_one(map->map[map->height - 1]);
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
				ft_printerrors("Incorrect characters\n");
			if (!ft_strchr("01CEP\n", map->map[i][j]))
				return (0);
			if (map->map[i][j] == 'P')
				map->player++;
			if (map->map[i][j] == 'C')
				map->collect++;
			if (map->map[i][j] == 'E')
				map->exit++;
			j++;
		}
		i++;
	}
	return (1);
}

void	valid_format(char *map_name, t_game *map)
{
	int	len;

	len = ft_strlen(map_name);
	if (len < 4)
	{
		ft_printerrors("file name");
		exit(1);
	}
	else
	{
		len--;
		if (map_name[len] != 'r' || map_name[len - 1] != 'e' || 
			map_name[len - 2] != 'b' || map_name[len - 3] != '.')
		{
			write(2, "Error: file format \n", 19);
			exit (1);
		}
	}
	map->name_map = map_name;
}
void	check_content(t_game *game)
{
	if (game->height < 3 || game->width < 6)
		ft_printerrors("Wrong map size");
	if (game->collect < 1)
		ft_printerrors("Wrong collectable number");
	if (game->exit != 1)
		ft_printerrors("Wrong exit number");
}