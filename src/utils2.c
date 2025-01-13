/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyuela <mhoyuela@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-11 16:00:36 by mhoyuela          #+#    #+#             */
/*   Updated: 2025-01-11 16:00:36 by mhoyuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_line(char **matrix, char *line_in_matrix, int fd)
{
	int	i;

	i = 0;
	while (line_in_matrix)
	{
		matrix[i] = ft_strdup(line_in_matrix);
		free(line_in_matrix);
		i++;
		line_in_matrix = get_next_line(fd, 0);
	}
}

int	if_not_fd(int fd)
{
	if (fd < 0)
	{
		ft_printf("ERROR: Load Failed\n");
		return (1);
	}
	return (0);
}
