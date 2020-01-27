/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utiles.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 02:59:29 by moel-mal          #+#    #+#             */
/*   Updated: 2019/11/12 15:09:18 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (c == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char*)(s + i));
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	if (!(tab = malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i] != '\0')
		tab[i] = s1[i];
	while (s2[++j] != '\0')
		tab[i + j] = s2[j];
	tab[i + j] = '\0';
	return (tab);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		ligne;
	char	*retur;

	i = 0;
	ligne = 0;
	while (s1[ligne] != '\0')
		ligne++;
	retur = malloc(sizeof(char) * (ligne + 1));
	if (!retur)
		return (NULL);
	while (s1[i] != '\0')
	{
		retur[i] = (char)s1[i];
		i++;
	}
	retur[i] = '\0';
	return (retur);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
