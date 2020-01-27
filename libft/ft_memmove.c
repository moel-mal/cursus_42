/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:29:55 by moel-mal          #+#    #+#             */
/*   Updated: 2019/10/23 05:55:47 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *constsrc;
	unsigned char *constdest;

	constsrc = (unsigned char*)src;
	constdest = (unsigned char*)dest;
	if (dest == src)
		return (dest);
	if (dest > src && src < dest + n)
	{
		constsrc = (unsigned char*)src + n - 1;
		constdest = (unsigned char*)dest + n - 1;
		while (n)
		{
			*constdest = *constsrc;
			constdest--;
			constsrc--;
			n--;
		}
	}
	else
		dest = ft_memcpy(dest, src, n);
	return (dest);
}
