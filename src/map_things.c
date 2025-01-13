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

void	ft_init_struct(t_g *g)
{
	g->collect = 0;
	g->exit = 0;
	g->player = 0;
	g->x = 0;
	g->y = 0;
	g->height = 0;
	g->width = 0;
	g->count = 0;
	g->moves = 0;
	g->name_map = '\0';
	g->map = NULL;
	g->map_copy = NULL;
}

void	map_staff(t_g *g, char *param, int i)
{
	i = 0;
	ft_init_struct(g);
	valid_format(param, g);
	g->map = make_matrix(param, g, i);
	if (!g->map)
		exit(1);
	g->map_copy = make_matrix(param, g, i);
	if (!g->map_copy)
		ft_error_free("invalid map", g);
	map_characther(g);
	check_content(g);
	save_player_pos(g);
	flood_fill(g, (g->y), (g->x));
	valid_flood_fill(g);
}

void	save_player_pos(t_g *g)
{
	int	i;
	int	j;

	i = 0;
	if (g->player != 1)
		ft_printerrors("wrong players number\n", g->map, g->map_copy);
	while (i < g->height)
	{
		j = 0;
		while (g->map[i][j] != '\0')
		{
			if (g->map[i][j] == 'P')
			{
				g->x = j;
				g->y = i;
			}
			j++;
		}
		i++;
	}
}

char	**make_matrix(char *path, t_g *g, int i)
{
	char	**matrix;
	char	*line_in_matrix;
	int		fd;

	fd = open(path, O_RDONLY);
	if (if_not_fd(fd))
		return (NULL);
	matrix = malloc(sizeof(char *) * (c_l(path, g) + 1));
	if (!matrix)
		ft_printerrors("Memory failure in matrix\n", g->map, g->map_copy);
	line_in_matrix = get_next_line(fd, 0);
	if (!line_in_matrix)
		ft_printerrors("Memory failure in matrix\n", g->map, g->map_copy);
	while (line_in_matrix)
	{
		matrix[i++] = ft_strdup(line_in_matrix);
		free(line_in_matrix);
		line_in_matrix = get_next_line(fd, 0);
	}
	g->height = i;
	matrix[i] = line_in_matrix;
	close(fd);
	free(line_in_matrix);
	line_in_matrix = NULL;
	return (matrix);
}

int	c_l(char *path, t_g *g)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	if (!path)
		ft_printerrors("Path not found\n", g->map, g->map_copy);
	fd = open(path, O_RDONLY);
	line = get_next_line(fd, 0);
	g->width = ft_strlen_sl(line);
	if (!line)
		ft_printerrors("Invalid map\n", g->map, g->map_copy);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd, 0);
		if (line && g->width != ft_strlen_sl(line))
			(free(line), get_next_line(fd, 1), ft_error_free(path, g));
	}
	close(fd);
	free(line);
	line = NULL;
	return (i);
}
