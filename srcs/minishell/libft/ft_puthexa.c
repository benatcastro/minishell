/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:32:27 by umartin-          #+#    #+#             */
/*   Updated: 2022/02/17 16:39:16 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthexa_x(unsigned long int n, int *num)
{
	char	*chars;

	chars = "0123456789abcdef";
	if (n / 16 > 0)
	{
		ft_puthexa_x(n / 16, num);
		ft_putchar_c(chars[n % 16], num);
	}
	else
		ft_putchar_c(chars[n], num);
}

void	ft_puthexa_xx(unsigned long int n, int *num)
{
	char	*chars;

	chars = "0123456789ABCDEF";
	if (n / 16 > 0)
	{
		ft_puthexa_xx(n / 16, num);
		ft_putchar_c(chars[n % 16], num);
	}
	else
		ft_putchar_c(chars[n], num);
}
