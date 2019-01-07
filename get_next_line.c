/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:52:30 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/01/07 17:34:24 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			cut_line(char **s, char **line)
{
	char	*tmp;
	int		len;

	if (ft_strchr(*s, '\n'))
	{
		len = ft_strclen(*s, '\n');
		if (!(*line = ft_strsub(*s, 0, len)))
			return (-1);
		if (!(tmp = ft_strdup(*s + len + 1)))
			return (-1);
		free(*s);
		*s = tmp;
	}
	else
	{
		if (!(*line = ft_strdup(*s)))
			return (-1);
		ft_strdel(s);
	}
	return (1);
}

int			read_files(int fd, char **s, int ret)
{
	char		buff[BUFF_SIZE + 1];
	char		*tmp;

	while ((ret = read(fd, &buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!(tmp = ft_strjoin(*s, buff)))
			return (-1);
		free(*s);
		*s = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (ret);
}

int			get_next_line(int fd, char **line)
{
	static char	*s[MAX_FD];
	int			ret;

	ret = 1;
	if (line == NULL || fd < 0)
		return (-1);
	if (!s[fd])
		if (!(s[fd] = ft_strnew(1)))
			return (-1);
	if (ft_strchr(s[fd], '\n'))
		return (cut_line(&s[fd], line));
	else
		ret = read_files(fd, &s[fd], ret);
	if (ret < 0)
		return (-1);
	if (ret == 0 && (s[fd][0] == '\0'))
		return (0);
	return (cut_line(&s[fd], line));
}
