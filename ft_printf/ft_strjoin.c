/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:55:52 by moel-mal          #+#    #+#             */
/*   Updated: 2019/10/24 14:45:03 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
