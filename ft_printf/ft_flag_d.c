/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:06:38 by moel-mal          #+#    #+#             */
/*   Updated: 2019/12/20 12:03:50 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	help(t_flag flag, int i, int res)
{
	if (res == 0 && flag.precesion == 0)
		i--;
	if (flag.option == 0 || (flag.precesion == 0 && flag.option == '0'))
	{
		ft_print_space(flag.width - i);
		if ((res != 0) || ((res == 0) && (flag.precesion != 0)))
			ft_putnbr_fd(res, 1);
	}
	else if (flag.option == '-')
	{
		if ((res != 0) || ((res == 0) && (flag.precesion != 0)))
			ft_putnbr_fd(res, 1);
		ft_print_space(flag.width - i);
	}
	else if (flag.option == '0')
		help_d(flag, i, res);
	return (flag.width);
}

static void	help2_1(t_flag flag, int i, int res)
{
	if (res < 0 && flag.width != flag.precesion + 1)
		ft_print_space(flag.width - flag.precesion - 1);
	else
		ft_print_space(flag.width - flag.precesion);
	if (res < 0)
	{
		if (res != -2147483648)
			ft_putchar_fd('-', 1);
		res = -res;
		if (flag.precesion + 1 != i)
			i--;
		if (flag.width == flag.precesion + 1)
			flag.precesion--;
	}
	if (res == 0)
		i = 0;
	ft_print_zero(flag.precesion - i);
	if (res != 0)
		ft_putnbr_fd(res, 1);
}

static int	help2(t_flag flag, int i, int res)
{
	if (flag.precesion + 1 < i)
		flag.precesion = i;
	if (flag.option == 0 || flag.option == '0')
		help2_1(flag, i, res);
	if (flag.option == '-')
	{
		if (res < 0)
		{
			if (res != -2147483648)
				ft_putchar_fd('-', 1);
			res = -res;
			if (flag.precesion != i)
				flag.precesion++;
		}
		if (flag.precesion > i)
			ft_print_zero(flag.precesion - i);
		ft_putnbr_fd(res, 1);
		ft_print_space(flag.width - flag.precesion);
	}
	return (flag.width);
}

static int	help3(t_flag flag, int i, int res)
{
	if (res == 0 && flag.precesion == 0)
		return (0);
	if (i > flag.precesion)
	{
		ft_putnbr_fd(res, 1);
		return (i);
	}
	else
	{
		if (res < 0)
		{
			if (res != -2147483648)
				ft_putchar_fd('-', 1);
			res = -res;
			flag.precesion++;
		}
		ft_print_zero(flag.precesion - i);
		ft_putnbr_fd(res, 1);
	}
	return (flag.precesion);
}

int			ft_set_intiger(va_list args, t_flag flag)
{
	int res;
	int i;

	res = va_arg(args, int);
	i = ft_get_size_int(res);
	if ((flag.width == 0 && flag.precesion == -1)
	|| (flag.width != 0 && i >= flag.width && flag.width >= flag.precesion &&
	res != 0))
		ft_putnbr_fd(res, 1);
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
