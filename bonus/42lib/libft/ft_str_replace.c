/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:17:12 by bena              #+#    #+#             */
/*   Updated: 2022/11/24 16:48:20 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief
 *
 * @param src -> pointer to a string allocated in heap which will be replaced
 * @param replace string which will replace src
 * @return 0 if any of the args is NULL 1 if the the replacement is succesfull
 */
char	*ft_str_replace(char *src, char const *replace)
{
	if (!replace)
		return (0);
	free(src);
	src = ft_strdup(replace);
	return (src);
}
