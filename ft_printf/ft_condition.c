/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 21:04:32 by moel-mal          #+#    #+#             */
/*   Updated: 2019/12/19 19:24:31 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void		ft_print_space(int i)
{
	if (i > 0)
	{
		while (i--)
			ft_putchar_fd(' ', 1);
	}
}

void		ft_print_zero(int i)
{
	if (i > 0)
	{
		while (i--)
			ft_putchar_fd('0', 1);
	}
}

  

int			ft_print(va_list args, t_flag flag)
{
	if (flag.convertion == 's')
		return (ft_set_string(args, flag));
	if (flag.convertion == 'd' || flag.convertion == 'i')
		return (ft_set_intiger(args, flag));
	if (flag.convertion == 'c' || flag.convertion == '%')
		return (ft_set_caractere(args, flag));
	if (flag.convertion == 'x' || flag.convertion == 'X')
		return (ft_set_hexa(args, flag));
	if (flag.convertion == 'u')
		return (ft_set_unsigned(args, flag));
	if (flag.convertion == 'p')
		return (ft_set_p(args, flag));
	return (0);
}
