/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderose <aderose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 12:05:16 by aderose           #+#    #+#             */
/*   Updated: 2020/08/23 13:22:46 by aderose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			pos_new_line(char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == '\n')
				return (i);
			i++;
		}
	}
	return (-1);
}

static void			separate_lines(char **line, char **next, char *tmp)
{
	if (tmp)
	{
		*line = ft_substr(*next, 0, pos_new_line(*next));
		ft_free(next);
		*next = ft_substr(tmp, 1, ft_strlen(tmp));
	}
	else
		*line = ft_substr(*next, 0, ft_strlen(*next));
	ft_free(&tmp);
}

static int			read_buf(int fd, char *buf, char **cur, char **line)
{
	ssize_t ret;
	int		end;

	*buf = '\0';
	while (pos_new_line(*cur) == -1 &&
			(ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		*cur = ft_strjoin(*cur, buf);
	}
	end = ret == 0 ? 1 : 0;
	if (*cur == NULL)
	{
		end = 0;
		if (!(*line = (char*)malloc(1)))
			return (-1);
		**line = '\0';
	}
	ft_free(&buf);
	return (end);
}

int					get_next_line(int fd, char **line)
{
	char			*buf;
	static char		*current = NULL;
	char			*new_line;
	int				is_end;

	buf = NULL;
	if (!line || fd < 0 || read(fd, buf, 0) < 0 || BUFFER_SIZE < 1)
		return (-1);
	if (!(buf = (char*)malloc(BUFFER_SIZE + 1)))
		return (-1);
	new_line = NULL;
	is_end = 0;
	if ((is_end = read_buf(fd, buf, &current, line)) == -1)
		return (-1);
	if ((new_line = ft_strchr(current, '\n')) != NULL)
	{
		separate_lines(line, &current, new_line);
		return (1);
	}
	if (is_end == 1)
	{
		*line = ft_substr(current, 0, ft_strlen(current));
		ft_free(&current);
	}
	return (0);
}
