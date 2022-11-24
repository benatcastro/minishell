/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublefree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:22:56 by aalvarez          #+#    #+#             */
/*   Updated: 2022/11/24 16:46:57 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief attempts to free a double pointer pointed by str.
 *
 * @param str the double pointer to free.
 * @return int 1 if the function couldn't free the string or 0 if it sucesfully
 * freed it.
 */
int	ft_doublefree(char **str)
{
	int	i;

	if (!str)
		return (1);
	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	return (0);
}
