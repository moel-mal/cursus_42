/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:52:16 by moel-mal          #+#    #+#             */
/*   Updated: 2019/10/24 14:29:26 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
