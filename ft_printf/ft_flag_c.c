/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 21:29:58 by moel-mal          #+#    #+#             */
/*   Updated: 2019/12/20 11:50:48 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static	int	help(t_flag flag, char c)
{
	if (flag.option == 0 || flag.option == '0')
	{
		if (flag.option == '0')
			ft_print_zero(flag.width - 1);
		else
			ft_print_space(flag.width - 1);
		ft_putchar_fd(c, 1);
	}
	if (flag.option == '-')
	{
		ft_putchar_fd(c, 1);
		ft_print_space(flag.width - 1);
	}
	return (flag.width);
}

int			ft_set_caractere(va_list args, t_flag flag)
{
	char c;

	if (flag.convertion != '%')
		c = va_arg(args, int);
	else
		c = '%';
	if (flag.width != 0)
		return (help(flag, c));
	else
		ft_putchar_fd(c, 1);
	return (1);
}
