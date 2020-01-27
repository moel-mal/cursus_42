/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:36:59 by moel-mal          #+#    #+#             */
/*   Updated: 2019/10/23 22:39:19 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned	int	i;
	char			*tab;

	if (!s)
		return (NULL);
	tab = (char *)malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < len && ft_strlen(s) > start)
	{
		tab[i] = s[start];
		i++;
		start++;
	}
	tab[i] = '\0';
	return (tab);
}
