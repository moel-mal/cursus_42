/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 00:26:29 by moel-mal          #+#    #+#             */
/*   Updated: 2019/12/20 13:39:24 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		signe;
	size_t	result;

	i = 0;
	signe = 1;
	result = 0;
	while ((str[i] <= 13 && str[i] >= 9) || (str[i] == 32))
		i++;
	if (str[i] == '-')
		signe = -signe;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] <= '9' && str[i] >= '0')
			result = result * 10 + (str[i++] - 48);
		else
			break ;
	}
	if (result >= 9223372036854775807 && signe == -1)
		return (0);
	else if (result >= 9223372036854775807 && signe == 1)
		return (-1);
	return (result * signe);
}
