/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:21:35 by moel-mal          #+#    #+#             */
/*   Updated: 2019/12/17 05:39:03 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static	int	ft_help(t_flag flag, char *tab, int i)
{
	if (flag.option == '-')
	{
		ft_putstr_fd(tab, 1);
		while (flag.width - i)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
	}
	else
	{
		while (flag.width != i)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
		ft_putstr_fd(tab, 1);
	}
	return (i);
}

static	int	help2(t_flag flag, char *tab, int i)
{
	if (flag.precesion < i)
	{
		tab = ft_substr(tab, 0, flag.precesion);
		ft_putstr_fd(tab, 1);
		i = flag.precesion;
	}
	else
		ft_putstr_fd(tab, 1);
	return (i);
}

static	int	help3(t_flag flag, char *tab, int i)
{
	if (flag.precesion < i && flag.precesion != -1)
	{
		tab = ft_substr(tab, 0, flag.precesion);
		i = flag.precesion;
	}
	if (flag.width > i)
		i = ft_help(flag, tab, i);
	else
		ft_putstr_fd(tab, 1);
	return (i);
}

int			ft_set_string(va_list args, t_flag flag)
{
	char	*tab;
	int		i;

	tab = va_arg(args, char*);
	if (tab == NULL)
		tab = ft_strdup("(null)");
	i = ft_strlen(tab);
	if (flag.width == 0 && flag.precesion == -1)
	{
		ft_putstr_fd(tab, 1);
		return (i);
	}
	if (flag.width != 0)
		i = help3(flag, tab, i);
	if (flag.precesion != -1 && flag.width == 0)
		i = help2(flag, tab, i);
	return (i);
}
