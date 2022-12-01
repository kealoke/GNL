/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushimom <yushimom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:16:16 by yushimom          #+#    #+#             */
/*   Updated: 2022/12/01 14:02:59 by yushimom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*read_and_save(int fd, char **save);
char	*get_line(char *save);
char	*get_next_save(char *save);
char	*ft_strjoin(char *s1, char *s2);
ssize_t	ft_read(int fd, char *buf, ssize_t size);
char	*ft_strchr(const char *src, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
#endif