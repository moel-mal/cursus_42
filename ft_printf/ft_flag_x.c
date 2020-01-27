/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:49:23 by moel-mal          #+#    #+#             */
/*   Updated: 2019/12/20 12:06:24 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	help(t_flag flag, int i, char *tab)
{
	if (tab[0] == '0' && flag.precesion == 0)
		i--;
	if (flag.option == 0 || (flag.precesion == 0 && flag.option == '0'))
	{
		ft_print_space(flag.width - i);
		if ((tab[0] != '0') || ((tab[0] == '0') && (flag.precesion != 0)))
			ft_putstr_fd(tab, 1);
	}
	else if (flag.option == '-')
	{
		if ((tab[0] != '0') || ((tab[0] == '0') && (flag.precesion != 0)))
			ft_putstr_fd(tab, 1);
		ft_print_space(flag.width - i);
	}
	else if (flag.option == '0')
	{
		ft_print_zero(flag.width - i);
		ft_putstr_fd(tab, 1);
	}
	return (flag.width);
}

static int	help2_1(t_flag flag, int i, char *tab)
{
	ft_print_zero(flag.precesion - i);
	ft_putstr_fd(tab, 1);
	ft_print_space(flag.width - flag.precesion);
	return (flag.width);
}

static int	help2(t_flag flag, int i, char *tab)
{
	if (flag.precesion + 1 < i)
		flag.precesion = i;
	if (flag.option == 0 || flag.option == '0')
	{
		if (i > flag.precesion)
			flag.precesion = i;
		ft_print_space(flag.width - flag.precesion);
		if (tab[0] == '0')
			i = 0;
		ft_print_zero(flag.precesion - i);
		if (tab[0] != '0')
			ft_putstr_fd(tab, 1);
	}
	if (flag.option == '-')
		help2_1(flag, i, tab);
	return (flag.width);
}

static int	help3(t_flag flag, int i, char *tab)
{
	if (tab[0] == '0' && flag.precesion == 0)
		return (0);
	if (i > flag.precesion)
	{
		ft_putstr_fd(tab, 1);
		return (i);
	}
	else
	{
		ft_print_zero(flag.precesion - i);
		ft_putstr_fd(tab, 1);
	}
	return (flag.precesion);
}

int			ft_set_hexa(va_list args, t_flag flag)
{
	unsigned int	res;
	char			*tab;
	int				i;

	res = va_arg(args, unsigned int);
	tab = convert_hexa(res, flag);
	i = ft_strlen(tab);
	if ((flag.width == 0 && flag.precesion == -1)
	|| (flag.width != 0 && i > flag.width && flag.width >= flag.precesion))
		ft_putstr_fd(tab, 1);
	else if ((flag.width != 0 && flag.precesion == -1) ||
		(flag.precesion == 0 && flag.width != 0))
		i = help(flag, i, tab);
	else if (flag.width != 0 && flag.precesion != -1
		&& flag.width > flag.precesion)
		i = help2(flag, i, tab);
	else if ((flag.width == 0 && flag.precesion != -1)
		|| (flag.width <= flag.precesion))
		i = help3(flag, i, tab);
	return (i);
}
