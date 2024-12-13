/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_things.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyuela <mhoyuela@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-02 16:02:42 by mhoyuela          #+#    #+#             */
/*   Updated: 2024-12-02 16:02:42 by mhoyuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_struct(t_game *game)
{
	game->collect = 0;
	game->exit = 0;
	game->player = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->height = 0;
	game->width = 0;
	game->count = 0;
	game->name_map = '\0';
}

void	map_staff(t_game *game, char *param)
{

	ft_init_struct(game);
	valid_format(param, game);
	game->map = make_matrix(param,game);
	game->map_copy = make_matrix(param,game);
	if (!game->map_copy)
		ft_error_free(param, game);
	//tengo que ver q solo haya un jugasor, una salida, y mas de un coleccionable
	map_characther(game);
	check_content(game);
	save_player_pos(game);
	flood_fill(game, (game->player_y), (game->player_x));
	//printf("llega\n");
	valid_flood_fill(game);

	//tengo que comprobar el exterior del mapa haciendo una funcion
	//tengo que comprobar el interior con la funcion map_character
}
void	save_player_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	if (game->player != 1)
		ft_printerrors("wrong players number\n");
	while (i < game->height)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = i;
				game->player_y = j;
			}
			j++;
		}
		i++;
	}
}
char	**make_matrix(char *path_to_file,t_game *game)
{
	char	**matrix;
	char	*line_in_matrix;
	int		i;
	int		fd;

	i = 0;
	fd = open(path_to_file, O_RDONLY);
	matrix = (char **)malloc(sizeof(char *) * (count_lines(path_to_file,game) + 1));
	if (!matrix)
		ft_printerrors("Memory failure in matrix\n");
	line_in_matrix = get_next_line(fd);
	if (!line_in_matrix)
		ft_printerrors("Memory failure in matrix\n");
	while (line_in_matrix)
	{
		matrix[i++] = ft_strdup(line_in_matrix);
		free(line_in_matrix);
		line_in_matrix = get_next_line(fd);
	}
	game->height = i;
	matrix[i] = line_in_matrix;
	close(fd);
	free(line_in_matrix);
	line_in_matrix = NULL;
	return (matrix);	
}
int	count_lines(char *path,t_game *game)
{
	int		i;
	int		fd;
	char	*line_in_matrix;

	if (!path)
		ft_printerrors("Path not found\n");
	fd = open(path, O_RDONLY);
	line_in_matrix = get_next_line(fd);
	game->width = ft_strlen_sl(line_in_matrix);
	if (!line_in_matrix)
		ft_printerrors("Invalid map\n");
	while (line_in_matrix)
	{
		i++;
		free(line_in_matrix);
		line_in_matrix = get_next_line(fd);
		if (line_in_matrix && game->width != ft_strlen_sl(line_in_matrix))
			ft_error_free(path, NULL);
	}
	close(fd);
	free(line_in_matrix);
	line_in_matrix = NULL;
	return (i);
}
