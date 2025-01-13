/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyuela <mhoyuela@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-05 11:36:32 by mhoyuela          #+#    #+#             */
/*   Updated: 2024-06-05 11:36:32 by mhoyuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(char const *content, ...);
int	ft_putptr(unsigned long long ptr);
int	ft_putchar(char c);
int	ft_puthexa(unsigned long long int n, char c);
int	ft_putnbr(int n);
int	ft_putstr(char *c);
int	ft_putunsigned(unsigned int n);

#endif