/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 02:04:34 by ksadiku           #+#    #+#             */
/*   Updated: 2022/01/19 17:01:05 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_read(const int fd, char **save)
{
	char	buff[BUFF_SIZE + 1];
	char	*temp;
	int		ret;

	ret = read(fd, buff, BUFF_SIZE);
	if (ret < 0)
		return (-1);
	while (ret > 0)
	{
		buff[ret] = '\0';
		if (*save == NULL)
			*save = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(*save, buff);
			free(*save);
			*save = temp;
		}
		if (ft_strchr(*save, '\n'))
			break ;
		ret = read(fd, buff, BUFF_SIZE);
	}
	return (ret);
}

static int	ft_fill_line(char **line, char **save)
{
	char	*temp;
	int		len;

	len = 0;
	while ((*save)[len] != '\n' && (*save)[len] != '\0')
		len++;
	if ((*save)[len] == '\n')
	{
		*line = ft_strsub(*save, 0, len);
		temp = ft_strdup(&((*save)[len + 1]));
		free(*save);
		*save = temp;
		if ((*save)[0] == '\0')
			ft_strdel(save);
	}
	else
	{
		*line = ft_strdup(*save);
		ft_strdel(save);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*save[FD_SIZE];
	int			ret;

	if (!line || fd < 0 || BUFF_SIZE <= 0 || fd >= FD_SIZE)
		return (-1);
	if (save[fd])
		if (ft_strchr(save[fd], '\n'))
			return (ft_fill_line(line, &save[fd]));
	ret = ft_read(fd, &save[fd]);
	if (ret < 0)
		return (-1);
	else if (save[fd] == NULL && ret == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (ft_fill_line(line, &save[fd]));
}
