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

void	ft_printerrors(char *str)
{
	ft_printf("ERROR: %s", str);
	exit(1);
}
void	ft_error_free(char *msg, t_game *game)
{
	int	i;

	i = 0;
	ft_printf("ERROR: %s", msg);
	if (!game->map_copy)
		return ;
	while (game->map_copy[i])
	{
		free(game->map_copy);
		game->map_copy[i] = NULL;
		i++;
	}
	free(game->map_copy);
	game->map_copy = NULL;
}