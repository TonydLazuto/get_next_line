/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderose <aderose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 12:05:16 by aderose           #+#    #+#             */
/*   Updated: 2021/05/24 10:27:52 by tonyd            ###   ########.fr       */
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
	}
	return (0);
}

static char			*split_lines(char **line, char *cur, int pos)
{
	char	*tmp;

	tmp = NULL;
	*line = ft_substr(cur, 0, pos);
	tmp = ft_substr(cur, pos + 1, ft_strlen(cur) - pos + 1);
	ft_free(&cur);
	cur = ft_strdup(tmp);
	ft_free(&tmp);
	return (cur);
}

static char			*read_buf(int fd, char *cur, int *ret)
{
	char	buf[BUFFER_SIZE + 1];
	int		pos;

	pos = pos_new_line(cur);
	while (pos == -1 && ((*ret = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[*ret] = '\0';
		cur = strjoinfree(cur, buf);
		pos = pos_new_line(cur);
	}
	if (*ret > 0)
		*ret = 1;
	return (cur);
}

int					get_next_line(int fd, char **line)
{
	static char	*cur = NULL;
	static int	ret = 0;
	int			pos;

	if (check_error(fd, &cur, line) == -1)
		return (-1);
	if (!(cur = read_buf(fd, cur, &ret)))
		return (-1);
	if (cur)
	{
		pos = pos_new_line(cur);
		if (pos != -1)
			cur = split_lines(line, cur, pos);
		else
			*line = ft_strdup(cur);
		if (ret == 0)
			ft_free(&cur);
	}
	else
		*line = ft_strdup("\0");
	return (ret);
}
