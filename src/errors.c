/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyuela <mhoyuela@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-02 16:44:18 by mhoyuela          #+#    #+#             */
/*   Updated: 2024-12-02 16:44:18 by mhoyuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
	return (NULL);
}

void	ft_printerrors(char *str, char **map, char **map_copy)
{
	ft_free_map(map);
	ft_free_map(map_copy);
	ft_printf("ERROR: %s", str);
	exit(1);
}

void	ft_error_free(char *msg, t_g *g)
{
	(void)msg;
	ft_printf("ERROR: invalid map construction\n");
	if (!g->map)
		exit(1);
}
