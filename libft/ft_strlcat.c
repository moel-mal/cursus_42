/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:02:32 by moel-mal          #+#    #+#             */
/*   Updated: 2019/10/23 05:37:57 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l_dst;
	size_t	l_src;

	l_dst = ft_strlen(dst);
	l_src = ft_strlen(src);
	i = 0;
	if (size <= l_dst)
		return (size + l_src);
	while (l_dst + i < (size - 1) && src[i] != '\0')
	{
		dst[l_dst + i] = src[i];
		i++;
	}
	dst[l_dst + i] = '\0';
	return (l_dst + l_src);
}
