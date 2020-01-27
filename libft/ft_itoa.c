/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 22:45:58 by moel-mal          #+#    #+#             */
/*   Updated: 2019/10/24 15:41:31 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		call_size(int n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	long	p;
	long	s;
	char	*tab;

	s = (long)n;
	p = call_size(n);
	if (s < 0)
		s = -s;
	tab = malloc(sizeof(char) * p + 1);
	if (!tab)
		return (NULL);
	tab[p] = '\0';
	p--;
	if (s == 0)
		tab[p] = '0';
	while (p + 1 != 0 && s != 0)
	{
		tab[p] = (s % 10) + '0';
		s = s / 10;
		p--;
	}
	if (n < 0)
		tab[0] = '-';
	return (tab);
}
