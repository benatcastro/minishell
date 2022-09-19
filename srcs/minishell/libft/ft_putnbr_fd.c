/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:49:09 by umartin-          #+#    #+#             */
/*   Updated: 2021/11/09 16:55:04 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	a;
	int		i;

	i = n;
	if (n <= -2147483647 - 1)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (i < 10 && i >= 0)
	{
		a = i + '0';
		write(fd, &a, 1);
	}
	else if (i >= 10)
	{
		ft_putnbr_fd(i / 10, fd);
		a = i % 10 + '0';
		write(fd, &a, 1);
	}
	else
	{
		write(fd, "-", 1);
		ft_putnbr_fd(n * -1, fd);
	}
}
