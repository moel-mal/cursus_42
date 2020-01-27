/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 04:46:24 by moel-mal          #+#    #+#             */
/*   Updated: 2019/10/23 05:06:58 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	int		i;

	i = ((count && size) ? (count * size) : 1);
	p = malloc(i);
	if (p)
		ft_bzero(p, i);
	return (p);
}
