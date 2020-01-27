/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:08:17 by moel-mal          #+#    #+#             */
/*   Updated: 2019/10/23 18:11:57 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	i = 0;
	if (dst[i] == '\0' && src[i] == '\0' && size > 100)
		return (0);
	while (size && src[i] != '\0' && i < (size - 1))
	{
		dst[i] = (char)src[i];
		i++;
	}
	if (size != 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}
