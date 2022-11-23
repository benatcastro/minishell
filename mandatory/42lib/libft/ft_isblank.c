/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:36:29 by becastro          #+#    #+#             */
/*   Updated: 2022/09/20 16:20:46 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isblank(unsigned char c)
{
	if ((c == ' ' || c == '\t' || c == '\f'
			|| c == '\r' || c == '\n' || c == '\v'))
		return (true);
	return (false);
}