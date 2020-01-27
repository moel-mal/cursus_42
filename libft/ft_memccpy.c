/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:28:22 by moel-mal          #+#    #+#             */
/*   Updated: 2019/10/23 23:43:15 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned	char	*ss;
	unsigned	char	*pp;
	int					i;

	ss = (unsigned char*)src;
	pp = (unsigned char*)dst;
	i = 0;
	while (n != 0)
	{
		pp[i] = ss[i];
		if (ss[i] == (unsigned char)c)
		{
			i++;
			dst = pp;
			return (void *)(dst + i);
		}
		i++;
		n--;
	}
	dst = pp;
	return (NULL);
}
