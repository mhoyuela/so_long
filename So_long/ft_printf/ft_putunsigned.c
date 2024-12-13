/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyuela <mhoyuela@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-07 09:50:22 by mhoyuela          #+#    #+#             */
/*   Updated: 2024-06-07 09:50:22 by mhoyuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	int	c;

	c = 0;
	if (n > 9)
		c += ft_putunsigned(n / 10);
	ft_putchar(n % 10 + '0');
	c++;
	return (c);
}
