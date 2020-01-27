/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 02:47:34 by moel-mal          #+#    #+#             */
/*   Updated: 2019/11/20 22:16:00 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*check_ft(char *save, char **line)
{
	char *str;

	str = NULL;
	if (save)
	{
		if ((str = ft_strchr(save, '\n')))
		{
			*str = '\0';
			*line = ft_strdup(save);
			ft_strcpy(save, ++str);
		}
		else
		{
			*line = ft_strdup(save);
			save = NULL;
		}
	}
	else
		*line = ft_strdup("");
	return (str);
}

void			help(char *buff, char **line)
{
	char *tmp;

	tmp = *line;
	*line = ft_strjoin(tmp, buff);
	free(tmp);
}

int				first_ft(char **save, char *buff, int fd, char **line)
{
	int			size_read;
	char		*str;

	str = check_ft(*save, line);
	while (!str)
	{
		if ((size_read = read(fd, buff, BUFFER_SIZE)) == 0)
		{
			free(buff);
			free(*save);
			*save = NULL;
			return (0);
		}
		*(buff + size_read) = '\0';
		if ((str = ft_strchr(buff, '\n')))
		{
			*str++ = '\0';
			free(*save);
			*save = ft_strdup(str);
		}
		help(buff, line);
	}
	free(buff);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char *save[1024];
	char		*buff;

	if ((read(fd, NULL, 0) != 0) || fd < 0)
		return (-1);
	if (BUFFER_SIZE >= 2147483647 || BUFFER_SIZE < 0)
		return (-1);
	if (!(buff = malloc(BUFFER_SIZE + 1)))
		return (-1);
	return (first_ft(&save[fd], buff, fd, line));
}
