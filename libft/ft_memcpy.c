/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:33:33 by moel-mal          #+#    #+#             */
/*   Updated: 2019/10/24 14:28:49 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned	char	*ss;
	unsigned	char	*pp;
	int					i;

	ss = (unsigned char*)src;
	pp = (unsigned char*)dst;
	if (!dst && !src)
		return (NULL);
	i = 0;
	while (n != 0)
	{
		pp[i] = ss[i];
		i++;
		n--;
	}
	dst = pp;
	return (dst);
}
