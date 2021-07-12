/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderose <aderose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 12:06:23 by aderose           #+#    #+#             */
/*   Updated: 2021/07/12 18:09:50 by tonyd            ###   ########.fr       */
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

char		*ft_strdup(char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1)))
		return (NULL);
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
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

char		*strjoinfree(char *s1, char *s2)
{
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	if (!s1)
	{
		if (!(str = ft_substr(s2, 0, ft_strlen(s2))))
			return (NULL);
		return (str);
	}
	str = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	ft_free(&s1);
	return (str);
}

