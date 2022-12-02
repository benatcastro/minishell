/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:53:48 by aalvarez          #+#    #+#             */
/*   Updated: 2022/11/24 16:48:03 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/**
 * @brief writes a character on a fd.
 * 
 * @param c character to write.
 * @param fd fd to be written.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
