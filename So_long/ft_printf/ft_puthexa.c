/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyuela <mhoyuela@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-06 10:48:37 by mhoyuela          #+#    #+#             */
/*   Updated: 2024-06-06 10:48:37 by mhoyuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long long int n, char c)
{
	long long int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthexa(n / 16, c);
	if (c == 'x')
		ft_putchar("0123456789abcdef"[n % 16]);
	else if (c == 'X')
		ft_putchar("0123456789ABCDEF"[n % 16]);
	count++;
	return (count);
}
