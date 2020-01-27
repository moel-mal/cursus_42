/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:38:51 by moel-mal          #+#    #+#             */
/*   Updated: 2019/12/19 18:38:02 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_manage_argument(va_list args, const char *mdr)
{
	t_flag	flag;
	int		i;

	ft_set_initial_strct(&flag);
	ft_set_struct(&flag, mdr, args);
	i = ft_print(args, flag);
	return (i);
}

int		ft_get_result(va_list args, const char *mdr)
{
	int i;

	i = 0;
	while (*mdr != '\0')
	{
		if (*mdr == '%' && *(mdr + 1) != '%')
		{
			mdr++;
			i = i + ft_manage_argument(args, mdr);
			while (ft_strchr("siduxXc%p", *mdr) == 0)
				mdr++;
			mdr++;
			if (*mdr == '\0')
				return (i);
		}
		else
		{
			if (*mdr == '%')
				mdr++;
			ft_putchar_fd(*mdr, 1);
			mdr++;
			i++;
		}
	}
	return (i);
}

int		ft_printf(const char *mdr, ...)
{
	int			i;
	va_list		args;

	va_start(args, mdr);
	i = ft_get_result(args, mdr);
	va_end(args);
	return (i);
}
