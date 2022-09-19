/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:29:50 by umartin-          #+#    #+#             */
/*   Updated: 2022/02/17 16:39:07 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_c(char c, int *num)
{
	write(1, &c, 1);
	(*num)++;
}

void	ft_putstr_s(char *str, int *num)
{
	int	c;

	c = 0;
	if (!str)
		*num += write(1, "(null)", 6);
	else
	{
		while (str[c] != '\0')
			ft_putchar_c(str[c++], num);
	}
}

void	ft_putnbr_di(int nb, int *num)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		*num = *num + 11;
		return ;
	}
	if (nb < 0)
	{
		ft_putchar_c('-', num);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr_di(nb / 10, num);
		ft_putchar_c(nb % 10 + '0', num);
	}
	else
		ft_putchar_c(nb + '0', num);
}

void	ft_putnbr_u(unsigned int nb, int *num)
{
	if (nb < 0)
	{
		ft_putchar_c('-', num);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr_u(nb / 10, num);
		ft_putchar_c(nb % 10 + '0', num);
	}
	else
		ft_putchar_c(nb + '0', num);
}
