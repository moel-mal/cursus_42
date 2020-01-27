/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 18:23:39 by moel-mal          #+#    #+#             */
/*   Updated: 2019/12/20 12:17:15 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void		ft_set_initial_strct(t_flag *flag)
{
	flag->option = 0;
	flag->width = 0;
	flag->precesion = -1;
	flag->convertion = 0;
}

void		ft_set_struct(t_flag *flag, const char *mdr, va_list args)
{
	flag->convertion = ft_set_convertion(mdr);
	flag->option = ft_set_option(mdr);
	flag->width = ft_set_width(flag, mdr, args);
	flag->precesion = ft_set_precesion(flag, mdr, args);
	if (flag->width < 0)
	{
		flag->width = flag->width * (-1);
		flag->option = '-';
	}
	if (flag->precesion < 0)
		flag->precesion = -1;
}

char		ft_set_convertion(const char *mdr)
{
	int i;

	i = 0;
	while (!(ft_strchr("sdiuxX%cp", mdr[i])))
		i++;
	return (mdr[i]);
}

char		ft_set_option(const char *mdr)
{
	if (mdr[0] == '-' || mdr[0] == '0')
		return (mdr[0]);
	return (0);
}

void		help_d(t_flag flag, int i, int res)
{
	if (res < 0)
	{
		if (res != -2147483648)
			ft_putchar_fd('-', 1);
		res = -res;
	}
	ft_print_zero(flag.width - i);
	ft_putnbr_fd(res, 1);
}
