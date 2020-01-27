/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 02:51:21 by moel-mal          #+#    #+#             */
/*   Updated: 2019/11/20 21:00:46 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int				get_next_line(const int fd, char **line);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*check_ft(char *save, char **line);
void			help(char *buff, char **line);
int				first_ft(char **save, char *buff, int fd, char **line);

#endif
