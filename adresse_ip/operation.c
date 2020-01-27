/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 16:27:21 by moel-mal          #+#    #+#             */
/*   Updated: 2019/11/04 16:52:15 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib.h"

int prefixe(int *tab, int pr)
{
		if (les_classe(tab) == 'A')
			return 8;
		if (les_classe(tab) == 'B')
			return 16;
		if (les_classe(tab) == 'C')
			return 24;
		return 0;
}
char les_classe(int *tab)
{
	int i;

	i = 0;
	if (tab[i] <= 127)
		return ('A');
	if (tab[i] > 127 && tab[i] <= 191)
		return ('B');
	if (tab[i] > 191 && tab[i] <= 223)
		return ('C');
	if (tab[i] > 223 && tab[i] <= 239)
		return ('D');
	if (tab[i] > 239 && tab[i] <= 255)
		return ('E');
	return (0);
}

int	*le_mask(int *tab,int pr)
{
	int *b;
	int i;
	int a;

	a = 0;
	i = 31;
	if (pr == 0)
		pr = prefixe(tab, pr);
	pr--;
	b = convetion_binaire(tab);
	while (i >= 0)
	{
		b[i] = a;
		i--;
		if (i == pr)
			a = 1;
	}
	return (binaire_to_decimale(b));
}

int *binaire_to_decimale(int *b)
{
	int *tab;
	int i;
	int j;
	int p;

	j = 31;
	i = 4;
	tab = malloc(sizeof (int) * 4);
	while (j >= 0)
	{
		if (j == 7 || j == 15 || j == 23 ||j == 31)
		{
			i--;
			tab[i] = 0;
			p = 1;
		}
		tab[i] = tab[i] + (b[j] * p);
		p = p * 2;
		j--;
	}
	return (tab);
}

int *broadcast(int *tab, int pr)
{
	int *b;
	int i;
	
	if (pr == 0)
		pr = prefixe(tab, pr);
	b = convetion_binaire(tab);
	while (pr <= 31)
	{
		b[pr] = 1;
		pr++;
	}
	return (binaire_to_decimale(b));
}

int host(int *tab, int pr)
{
	int i;
	int res;
	int p;

	i = 31;
	res = 1;
	if (pr == 0)
		pr = prefixe(tab, pr);
	pr--;
	while (i > pr)
	{
		res = res * 2;
		i--;
	}
	return (res -2);
}
