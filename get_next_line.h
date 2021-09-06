/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderose <aderose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 12:04:51 by aderose           #+#    #+#             */
/*   Updated: 2021/09/06 16:36:53 by aderose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>

int				get_next_line(int fd, char **line);
void			my_free(char **s);
size_t			my_strlen(const char *str);
char			*strjoinfree(char *s1, char *s2);
char			*my_strdup(char *s1);
char			*my_substr(char *s, unsigned int start, size_t len);

#endif
