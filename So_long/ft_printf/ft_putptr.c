/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyuela <mhoyuela@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-06 14:50:22 by mhoyuela          #+#    #+#             */
/*   Updated: 2024-06-06 14:50:22 by mhoyuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long long ptr)
{
	int	c;

	c = 0;
	if (!ptr)
	{
		return (ft_putstr("(nil)"));
	}
	c += ft_putstr("0x");
	c += ft_puthexa(ptr, 'x');
	return (c);
}
