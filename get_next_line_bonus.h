/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushimom <yushimom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:16:16 by yushimom          #+#    #+#             */
/*   Updated: 2022/12/04 21:51:32 by yushimom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char		*get_next_line(int fd);
char		*read_and_save_b(int fd, char **save);
char		*get_line_b(char *save);
char		*get_next_save_b(char *save);
void		*ft_free_b(char *buf, char *save);
char		*ft_strjoin_b(char *s1, char *s2);
char		*ft_strchr_b(const char *src, int c);
char		*ft_substr_b(char const *s, unsigned int start, size_t len);
size_t		ft_strlcat_b(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen_b(const char *str);
#endif