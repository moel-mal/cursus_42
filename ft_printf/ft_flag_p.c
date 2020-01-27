/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 23:27:07 by moel-mal          #+#    #+#             */
/*   Updated: 2019/12/19 20:37:31 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	help(t_flag flag, int i, char *tab)
{
	if (tab[2] == '0' && flag.precesion == 0)
	{
		free(tab);
		tab = ft_strdup("0x");
		i--;
	}
	if (flag.option == 0 || (flag.precesion == 0 && flag.option == '0'))
	{
		ft_print_space(flag.width - i);
		ft_putstr_fd(tab, 1);
	}
	else if (flag.option == '-')
	{
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

static int	help2(t_flag flag, int i, char *tab)
{
	if (flag.option == 0 || flag.option == '0')
	{
		if (tab >= 0)
			ft_print_space(flag.width - flag.precesion);
		else
			ft_print_space(flag.width - flag.precesion - 1);
		if (tab[2] == '0')
			i = 0;
		ft_print_zero(flag.precesion - i);
		if (tab[2] != '0')
			ft_putstr_fd(tab, 1);
	}
	if (flag.option == '-')
	{
		ft_print_zero(flag.precesion - i);
		ft_putstr_fd(tab, 1);
		ft_print_space(flag.width - flag.precesion);
		return (flag.width);
	}
	return (flag.width);
}

static int	help3(t_flag flag, int i, char *tab)
{
	if (tab[2] == '0' && flag.precesion == 0)
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

static	int	device(t_flag flag, int i, char *tab, unsigned long long res)
{
	if ((flag.width == 0 && flag.precesion == -1)
	|| (flag.width != 0 && i > flag.width && flag.width >= flag.precesion &&
	res != 0) || (flag.width < 2 && res == 0 && flag.precesion == -1))
		ft_putstr_fd(tab, 1);
	else if ((flag.width != 0 && flag.precesion == -1) ||
		(flag.precesion == 0 && flag.width != 0 && flag.width > 2))
		i = help(flag, i, tab);
	else if (flag.precesion == 0 && res == 0 && flag.width <= 2)
	{
		ft_putstr_fd("0x", 1);
		return (2);
	}
	else if (flag.width != 0 && flag.precesion != -1
		&& flag.width >= flag.precesion)
		i = help2(flag, i, tab);
	else if ((flag.width == 0 && flag.precesion != -1)
		|| (flag.width < flag.precesion))
		i = help3(flag, i, tab);
	return (i);
}

int			ft_set_p(va_list args, t_flag flag)
{
	unsigned long long		res;
	char					*tab;
	int						i;

	res = va_arg(args, unsigned long long);
	tab = convert_hexa_p(res);
	tab = ft_strjoin("0x", tab);
	i = ft_strlen(tab);
	return (device(flag, i, tab, res));
}
