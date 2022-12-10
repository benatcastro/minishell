/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:54:15 by umartin-          #+#    #+#             */
/*   Updated: 2022/12/10 14:11:17 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_type(char t, va_list args, int *num)
{
	if (t == 'c')
		ft_putchar_c(va_arg(args, int), num);
	if (t == 's')
		ft_putstr_s(va_arg(args, char *), num);
	if (t == 'p')
	{
		*num += write(2, "0x", 2);
		ft_puthexa_x(va_arg(args, unsigned long int), num);
	}
	if (t == 'd' || t == 'i')
		ft_putnbr_di(va_arg(args, int), num);
	if (t == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), num);
	if (t == 'x')
		ft_puthexa_x(va_arg(args, unsigned int), num);
	if (t == 'X')
		ft_puthexa_xx(va_arg(args, unsigned int), num);
	if (t == '%')
		ft_putchar_c('%', num);
}

int	printerr(const char *str, ...)
{
	va_list	args;
	int		i;
	int		num;

	i = 0;
	num = 0;
	va_start (args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_type(str[i + 1], args, &num);
			i += 2;
			continue ;
		}
		ft_putchar_c(str[i], &num);
		i++;
	}
	va_end (args);
	return (num);
}
