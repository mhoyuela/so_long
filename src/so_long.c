/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyuela <mhoyuela@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-21 15:50:43 by mhoyuela          #+#    #+#             */
/*   Updated: 2024-11-21 15:50:43 by mhoyuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_g	g;

	if (argc != 2)
	{
		ft_printf("Error number of arguments \n");
		return (2);
	}
	else
	{
		map_staff(&g, argv[1], 0);
	}
	init_mlx_g(&g);
	g.map = ft_free_map(g.map);
	ft_free_map(g.map_copy);
}
