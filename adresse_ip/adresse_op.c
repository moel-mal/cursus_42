/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adresse_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:34:03 by moel-mal          #+#    #+#             */
/*   Updated: 2019/12/20 13:48:41 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int ip_prive(int *tab)
{
	int i;

	i = 0;
	if (tab[i] == 10)
		return 1;
	if (tab[i] == 172)
	{
		i++;
		if (tab[i] <= 31 && tab[i] >= 16)
			return 1;
		else
			return 0;
	}
	if (tab[i] == 192 && tab[i + 1] == 168)
		return 1;
	return 0;
}

int *adress_reseau(int *tab, int pr)
{
	int *b;
	int i;

	if (pr == 0)
		pr = prefixe(tab, pr);
	b = convetion_binaire(tab);
	while (pr <= 31)
	{
		b[pr] = 0;
		pr++;
	}
	return (binaire_to_decimale(b));
}

int *convetion_binaire(int *tab)
{
	int *b;
	int i;
	int j;
	int dev;

	b = malloc(sizeof(int) * 32);
	i = 3;
	j = 31;
	dev = tab[i];
	while (j >= 0)
	{
		if (j == 7 ||  j == 15 || j == 23)
		{
			i--;
			dev = tab[i];
		}
		b[j] = dev % 2;
		dev = dev / 2;
		j--;
	}
	return (b);
}

void print_ip(int *tab)
{
	int i;

	i = 0;
	while (i <= 3)
	{
		printf("%d",tab[i]);
		if (i != 3)
			printf(".");
		else
			printf("\n");
		i++;
	}
}


void print_ip_binaire(int *tab)
{
	int i;

	i = 0;
	while (i <= 31)
	{
		printf("%d",tab[i]);
		if (i == 7 || i == 15 || i == 23)
			printf(".");
		else if (i == 31)
			printf("\n");
		i++;
	}
}

int main()
{
	char *str;
	char **tab1;
	int *tab;
	int i;
	int prefix;

	tab = malloc(sizeof(int) * 4);
	
	i = 0;
	printf("saisir l'adresse ip :\n");
	scanf("%s", str);
	tab1 = ft_split(str, '.');
	while (i <= 3)
	{
		tab[i] = ft_atoi(tab1[i]);
		i++;
	}
	/*while(i <= 3)
	{
		scanf("%d",&tab[i]);
		if (tab[i] < 0 || tab[i] > 255)
		{
			printf("\nadresse ip non valide try again\n");
			i = -1;
		}
		i++;
	}*/
	printf("saisir le prefixe :");
	scanf("%d",&prefix);
	printf("\n***********************\n");
	printf("l'adresse ip :");
	print_ip(tab);
	printf("\n***********************\n");
	if (ip_prive(tab) == 1)
		printf("l'adresse est prive");
	else
		printf("l'adresse est public");
	printf("\n***********************\n");
	printf("\nclasse : [%c]\n",les_classe(tab));
	printf("\n***********************\n");
	printf("\nle mask : ");
	print_ip(le_mask(tab,prefix));
	printf("\n***********************\n");
	printf("\nbradcast : ");
	print_ip(broadcast(tab,prefix));
	printf("\n***********************\n");
	printf("adresse reseau : ");
	print_ip(adress_reseau(tab,prefix));
	printf("\n***********************\n");
	printf("\nle nombre de host est : %d\n",host(tab, prefix));
}
