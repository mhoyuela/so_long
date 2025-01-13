/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyuela <mhoyuela@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-05 11:54:52 by mhoyuela          #+#    #+#             */
/*   Updated: 2024-06-05 11:54:52 by mhoyuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

static	int	ft_filter(char const *content, int i, va_list *args)
{
	int	c;

	c = 0;
	if (content[i] == 'c')
		c += ft_putchar(va_arg(*args, int));
	if (content[i] == 's')
		c += ft_putstr(va_arg(*args, char *));
	if (content[i] == 'p')
		c += ft_putptr(va_arg(*args, unsigned long long));
	if (content[i] == 'x')
		c += ft_puthexa(va_arg(*args, unsigned int), 'x');
	if (content[i] == 'X')
		c += ft_puthexa(va_arg(*args, unsigned int), 'X');
	if (content[i] == 'd')
		c += ft_putnbr(va_arg(*args, int));
	if (content[i] == 'i')
		c += ft_putnbr(va_arg(*args, int));
	if (content[i] == 'u')
		c += ft_putunsigned(va_arg(*args, unsigned int));
	if (content[i] == '%')
		c += ft_putchar('%');
	return (c);
}

int	ft_printf(char const *content, ...)
{
	va_list	args;
	int		i;
	int		c;

	i = 0;
	c = 0;
	va_start(args, content);
	while (content[i])
	{
		if (content[i] != '%')
			c += ft_putchar(content[i]);
		else
		{
			i++;
			c += ft_filter(content, i, &args);
		}
		i++;
	}
	va_end(args);
	return (c);
}
