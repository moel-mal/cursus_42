/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:57:08 by moel-mal          #+#    #+#             */
/*   Updated: 2019/12/16 15:11:31 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	ft_set_width_1(const char *mdr, va_list args, int i)
{
	int		j;
	char	*tab;

	j = 0;
	while (mdr[i] == '0' || mdr[i] == '-')
		i++;
	if (mdr[i] == '*')
		return (va_arg(args, int));
	while (mdr[i + j] <= '9' && mdr[i + j] >= '0')
		j++;
	tab = malloc(sizeof(char) * j + 1);
	j = 0;
	while (mdr[i + j] <= '9' && mdr[i + j] >= '0')
	{
		tab[j] = mdr[i + j];
		j++;
	}
	tab[j] = '\0';
	i = ft_atoi(tab);
	free(tab);
	return (i);
}

int			ft_set_width(t_flag *flag, const char *mdr, va_list args)
{
	int i;

	i = 0;
	if ((flag->option == 0) && mdr[i] > '9' && mdr[i] < '0' && mdr[i] != '*')
		return (0);
	else if (flag->option != 0 && mdr[1] > '9' && mdr[1] < '0' && mdr[i] != '*')
		return (0);
	else
		return (ft_set_width_1(mdr, args, i));
}

static int	ft_set_precesion_1(const char *mdr, va_list args, int i)
{
	int		j;
	char	*tab;

	j = 0;
	i++;
	if ((mdr[i] < 0 && mdr[i] > 9) && mdr[i] != '*')
		return (0);
	if (mdr[i] == '*')
		return (va_arg(args, int));
	while (mdr[j + i] <= '9' && mdr[j + i] >= '0')
		j++;
	tab = malloc(sizeof(char) * j + 1);
	j = 0;
	while (mdr[j + i] <= '9' && mdr[j + i] >= '0')
	{
		tab[j] = mdr[j + i];
		j++;
	}
	tab[j] = '\0';
	i = ft_atoi(tab);
	free(tab);
	return (i);
}

int			ft_set_precesion(t_flag *flag, const char *mdr, va_list args)
{
	int	i;

	i = 0;
	while (mdr[i] != flag->convertion)
	{
		if (mdr[i] == '.')
			return (ft_set_precesion_1(mdr, args, i));
		i++;
	}
	return (-1);
}
