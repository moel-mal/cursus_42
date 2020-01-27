/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:32:33 by moel-mal          #+#    #+#             */
/*   Updated: 2019/12/20 12:04:38 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

typedef	struct	s_flag
{
	char		option;
	int			width;
	int			precesion;
	char		convertion;
}				t_flag;

int				ft_printf(const char *mdr, ...);
int				ft_get_result(va_list args, const char *mdr);
int				ft_manage_argument(va_list args, const char *mdr);
void			ft_set_initial_strct(t_flag *flag);
void			ft_set_struct(t_flag *flag, const char *mdr, va_list args);
char			ft_set_convertion(const char *mdr);
int				ft_check_convertion(char ch);
char			ft_set_option(const char *mdr);
int				ft_set_width(t_flag *flag, const char *mdr, va_list args);
int				ft_set_precesion(t_flag *flag, const char *mdr, va_list args);
void			ft_putstruct(t_flag flag);
int				ft_print(va_list args, t_flag flag);
int				ft_set_string(va_list args, t_flag flag);
int				ft_get_size_int(int res);
int				ft_set_intiger(va_list args, t_flag flag);
void			ft_print_space(int i);
void			ft_print_zero(int i);
int				ft_set_caractere(va_list args, t_flag flag);
char			*convert_hexa(unsigned int res, t_flag flag);
int				ft_set_hexa(va_list args, t_flag flag);
int				ft_set_unsigned(va_list args, t_flag flag);
int				ft_get_size_unsigned(unsigned long res);
void			ft_putnbr(unsigned long n);
int				ft_set_p(va_list args, t_flag flag);
char			*convert_hexa_p(unsigned long long res);
void			help_d(t_flag flag, int i, int res);

#endif
