/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderose <aderose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 12:04:51 by aderose           #+#    #+#             */
/*   Updated: 2021/05/21 13:30:12 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>

int				get_next_line(int fd, char **line);
void			ft_free(char **s);
size_t			ft_strlen(const char *str);
char			*strjoinfree(char *s1, char *s2);
char			*ft_strdup(char *s1);
char			*ft_substr(char *s, unsigned int start, size_t len);

#endif
