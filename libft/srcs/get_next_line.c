/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:34:00 by mfahey            #+#    #+#             */
/*   Updated: 2019/01/18 17:18:58 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_line(char **buff, char **line)
{
	size_t	i;
	char	*tmp;

	if (!(*buff))
		return (0);
	if (ft_strchr(*buff, '\n') == NULL)
	{
		if ((*line = ft_strdup(*buff)) == NULL)
			return (-1);
		ft_strdel(buff);
		return (ft_strlen(*line));
	}
	i = 0;
	while ((*buff)[i] != '\n')
		i++;
	if (((*line = ft_strsub(*buff, 0, i)) == NULL) ||
			((tmp = ft_strdup(*buff + i + 1)) == NULL))
		return (-1);
	ft_strdel(buff);
	if ((*buff = ft_strdup(tmp)) == NULL)
		return (-1);
	ft_strdel(&tmp);
	return (ft_strlen(*line));
}

static int	ft_buff(char *str, char **buff)
{
	char	*tmp;

	if (*buff == NULL)
	{
		if ((*buff = ft_strdup(str)) == NULL)
			return (-1);
	}
	else
	{
		if ((tmp = ft_strdup(*buff)) == NULL)
			return (-1);
		ft_strdel(buff);
		if ((*buff = ft_strjoin(tmp, str)) == NULL)
			return (-1);
		ft_strdel(&tmp);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*buff[8000];
	char		str[BUFF_SIZE + 1];
	int			ret;

	if ((fd < 0) || (fd == 1) || (fd == 2) || (fd >= 8000) ||
			!(line) || (BUFF_SIZE <= 0) || (BUFF_SIZE > 8384215))
		return (-1);
	while ((ret = read(fd, str, BUFF_SIZE)) > 0)
	{
		str[ret] = '\0';
		if ((ft_buff(str, &buff[fd])) == -1)
			return (-1);
		if ((ft_strchr(buff[fd], '\n')) != NULL)
			break ;
	}
	if (ret >= 0)
	{
		if (((ret = ft_line(&buff[fd], line)) > 0) || (buff[fd]))
			return (1);
		if (ret == 0)
			**line = '\0';
		return (0);
	}
	return (-1);
}
