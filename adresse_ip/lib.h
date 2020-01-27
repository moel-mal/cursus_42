/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:26:55 by moel-mal          #+#    #+#             */
/*   Updated: 2019/12/20 13:43:02 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

int             *convetion_binaire(int *tab);
void            print_ip(int *tab);
void            print_ip_binaire(int *tab);
char            les_classe(int *tab);
int             *le_mask(int *tab,int pr);
int             *binaire_to_decimale(int *b);
int             *broadcast(int *tab, int pr);
int             prefixe(int *tab, int pr);
int             host(int *tab, int pr);
char			**ft_split(const char *str, char c);
int	            ft_atoi(const char *str);

#endif
