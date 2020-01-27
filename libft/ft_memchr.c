/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:06:01 by moel-mal          #+#    #+#             */
/*   Updated: 2019/10/23 05:12:06 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned	char	*tab;
	unsigned	char	t;

	t = (unsigned char)c;
	tab = (unsigned	char*)s;
	while (n != 0)
	{
		if (*tab == t)
			return ((void*)(tab));
		tab++;
		n--;
	}
	return (NULL);
}
