/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderose <aderose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 12:06:23 by aderose           #+#    #+#             */
/*   Updated: 2020/07/16 16:08:39 by aderose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		ft_free(char **s)
{
	free(*s);
	*s = NULL;
}

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != '\0')
			i++;
	}
	return (i);
}

char		*ft_strchr(char *s, int c)
{
	char	*str;
	size_t	i;

	i = 0;
	str = NULL;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			str = ft_substr(s, i, ft_strlen(s));
			return (str);
		}
		i++;
	}
	if (s[i] == c)
	{
		str = ft_substr(s, i, ft_strlen(s));
		return (str);
	}
	return (NULL);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = ft_substr(s2, 0, ft_strlen(s2));
		return (s1);
	}
	if (!(str = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
	{
		ft_free(&s1);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	ft_free(&s1);
	return (str);
}

char		*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	if (!(str = (char*)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (i < len && s[i + start] != '\0')
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}
