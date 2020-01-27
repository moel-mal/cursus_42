/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_need.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:34:31 by moel-mal          #+#    #+#             */
/*   Updated: 2019/12/19 19:46:09 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	ft_set_module_p(int res)
{
	if (res <= 9 && res >= 0)
		return (res + '0');
	else if (res > 9)
		return (res - 10 + 'a');
	else
		return (0);
}

char		*convert_hexa_p(unsigned long long res)
{
	int					i;
	unsigned long long	tmp;
	unsigned long long	tmp1;
	char				*tab;

	if (res == 0)
		tab = ft_strdup("0");
	else
	{
		i = 0;
		tmp1 = res;
		tmp = res;
		while ((tmp1 = tmp1 / 16))
			i++;
		tab = malloc(sizeof(char) * i + 2);
		tab[i + 1] = '\0';
		while (tmp != 0)
		{
			tab[i] = ft_set_module_p(tmp % 16);
			tmp = tmp / 16;
			i--;
		}
	}
	return (tab);
}

int			ft_get_size_int(int res)
{
	int i;

	i = 0;
	if (res == 0)
		return (1);
	if (res < 0)
	{
		i++;
		res = -res;
	}
	while (res)
	{
		res = res / 10;
		i++;
	}
	return (i);
}

void		ft_putnbr(unsigned long n)
{
	if (n == 0)
		ft_putchar_fd('0', 1);
	else if (n <= 9 && n > 0)
		ft_putchar_fd(n + '0', 1);
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int			ft_get_size_unsigned(unsigned long res)
{
	int i;

	i = 0;
	if (res == 0)
		return (1);
	while (res)
	{
		res = res / 10;
		i++;
	}
	return (i);
}
