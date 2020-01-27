/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:15:44 by moel-mal          #+#    #+#             */
/*   Updated: 2019/10/23 05:16:31 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int					i;
	unsigned	char	*rtn;

	rtn = b;
	i = 0;
	while (i < (int)len)
	{
		rtn[i] = c;
		i++;
	}
	return (b);
}
