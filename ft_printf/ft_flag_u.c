/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 02:21:01 by moel-mal          #+#    #+#             */
/*   Updated: 2019/12/20 12:05:37 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	help(t_flag flag, int i, unsigned	long res)
{
	if (res == 0 && flag.precesion == 0)
		i--;
	if (flag.option == 0 || (flag.precesion == 0 && flag.option == '0'))
	{
		ft_print_space(flag.width - i);
		if ((res != 0) || ((res == 0) && (flag.precesion != 0)))
			ft_putnbr(res);
	}
	else if (flag.option == '-')
	{
		if ((res != 0) || ((res == 0) && (flag.precesion != 0)))
			ft_putnbr(res);
		ft_print_space(flag.width - i);
	}
	else if (flag.option == '0')
	{
		ft_print_zero(flag.width - i);
		ft_putnbr(res);
	}
	return (flag.width);
}

static int	help2_1(t_flag flag, int i, unsigned	long res)
{
	ft_print_zero(flag.precesion - i);
	ft_putnbr(res);
	ft_print_space(flag.width - flag.precesion);
	return (flag.width);
}

static int	help2(t_flag flag, int i, unsigned	long res)
{
	if (flag.precesion + 1 < i)
		flag.precesion = i;
	if (flag.option == 0 || flag.option == '0')
	{
		if (i > flag.precesion)
			flag.precesion = i;
		ft_print_space(flag.width - flag.precesion);
		if (res == 0)
			i = 0;
		ft_print_zero(flag.precesion - i);
		if (res != 0)
			ft_putnbr(res);
	}
	if (flag.option == '-')
		help2_1(flag, i, res);
	return (flag.width);
}

static int	help3(t_flag flag, int i, unsigned	long res)
{
	if (res == 0 && flag.precesion == 0)
		return (0);
	if (i > flag.precesion)
	{
		ft_putnbr(res);
		return (i);
	}
	else
	{
		ft_print_zero(flag.precesion - i);
		ft_putnbr(res);
	}
	return (flag.precesion);
}

int			ft_set_unsigned(va_list args, t_flag flag)
{
	unsigned	long	res;
	int					i;

	res = (unsigned long)va_arg(args, unsigned	int);
	i = ft_get_size_unsigned(res);
	if ((flag.width == 0 && flag.precesion == -1)
	|| (flag.width != 0 && i > flag.width && flag.width >= flag.precesion))
		ft_putnbr(res);
	else if ((flag.width != 0 && flag.precesion == -1) ||
		(flag.precesion == 0 && flag.width != 0))
		i = help(flag, i, res);
	else if (flag.width != 0 && flag.precesion != -1
		&& flag.width > flag.precesion)
		i = help2(flag, i, res);
	else if ((flag.width == 0 && flag.precesion != -1)
		|| (flag.width <= flag.precesion))
		i = help3(flag, i, res);
	return (i);
}
