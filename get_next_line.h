/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushimom <yushimom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:36:23 by yushimom          #+#    #+#             */
/*   Updated: 2022/12/04 21:51:42 by yushimom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char		*get_next_line(int fd);
char		*read_and_save(int fd, char **save);
char		*get_line(char *save);
char		*get_next_save(char *save);
void		*ft_free(char *buf, char *save);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *src, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *str);
#endif