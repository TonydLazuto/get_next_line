/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderose <aderose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 12:05:16 by aderose           #+#    #+#             */
/*   Updated: 2021/05/24 12:31:16 by tonyd            ###   ########.fr       */
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

static int			check_error(int fd, char **cur, char **line)
{
	if (!line || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	if (!*cur)
	{
		if (!(*cur = (char*)malloc(BUFFER_SIZE + 1)))
			return (-1);
		*cur[0] = '\0';
	}
	return (0);
}

static char			*split_lines(char **line, char *cur, int pos)
{
	char	*tmp;

	tmp = NULL;
	if (!(*line = ft_substr(cur, 0, pos)))
		return (NULL);
	if (!(tmp = ft_substr(cur, pos + 1, ft_strlen(cur) - pos + 1)))
		return (NULL);
	ft_free(&cur);
	if (!(cur = ft_strdup(tmp)))
		return (NULL);
	ft_free(&tmp);
	return (cur);
}

static char			*read_buf(int fd, char *cur, int *ret, char **line)
{
	char	buf[BUFFER_SIZE + 1];
	int		pos;

	pos = pos_new_line(cur);
	if (*ret == 1)
	{
		while (pos == -1 && ((*ret = read(fd, buf, BUFFER_SIZE)) > 0))
		{
			buf[*ret] = '\0';
			if (!(cur = strjoinfree(cur, buf)))
				return (NULL);
			pos = pos_new_line(cur);
		}
		if (*ret > 0)
		{
			if (pos != -1)
				if (!(cur = split_lines(line, cur, pos)))
					return (NULL);
			*ret = 1;
		}
	}
	return (cur);
}

int					get_next_line(int fd, char **line)
{
	static char	*cur = NULL;
	static int	ret = 1;

	if (check_error(fd, &cur, line) == -1)
		return (-1);
	if (!(cur = read_buf(fd, cur, &ret, line)))
		return (-1);
	if (ret <= 0)
	{
		if (ret == -3)
			*line = ft_strdup("\0");
		else if (ret == -2)
		{
			*line = ft_strdup(cur);
			ft_free(&cur);
			ret = -3;
		}
		else if (ret == 0)
		{
			ret = -2;
			*line = ft_strdup(cur);
		}
		return (0);
	}	
	return (1);
}
