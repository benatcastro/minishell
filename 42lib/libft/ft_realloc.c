/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:23:57 by bena              #+#    #+#             */
/*   Updated: 2022/09/20 12:39:03 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief
 * Doesn't shrink data, only enlarges the pointer,
 * needs testint
 * =====FIRST ITERATION======
 * @param ptr
 * @param size
 * @return void*
 */
void	*ft_realloc(void *ptr, size_t size)
{
	void	*realloc;

	if (!ptr)
		return (malloc(size));
	realloc = malloc(size);
	if (!realloc)
		return (NULL);
	ft_memcpy(realloc, ptr, size);
	return (realloc);
}
