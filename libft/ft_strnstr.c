/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 21:07:04 by moel-mal          #+#    #+#             */
/*   Updated: 2019/10/24 00:06:50 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	r;

	i = 0;
	r = 0;
	if (needle[r] == '\0')
		return (char *)haystack;
	while (needle[r] != '\0')
		r++;
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && needle[j] != '\0' && i + j < len)
			j++;
		if (r == j)
			return ((char*)(haystack + i));
		i++;
	}
	return (0);
}
