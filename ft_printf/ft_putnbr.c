/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyuela <mhoyuela@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-05 16:29:10 by mhoyuela          #+#    #+#             */
/*   Updated: 2024-06-05 16:29:10 by mhoyuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_counter(long int nbr)
{
	int	i;

	i = 0;
	if (nbr <= 0)
		i++;
	while (nbr > 0)
	{
		i++;
		nbr = (nbr / 10);
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long int	nbr;
	char		r;
	int			i;

	i = 0;
	nbr = (long int)n;
	if (nbr < 0)
	{
		i = ft_counter(nbr);
		nbr = nbr * -1;
		write (1, "-", 1);
	}
	if (nbr >= 0 && nbr <= 9)
	{
		r = nbr + '0';
		write (1, &r, 1);
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	return (ft_counter(nbr) + i);
}
