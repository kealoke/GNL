/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushimom <yushimom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:16:13 by yushimom          #+#    #+#             */
/*   Updated: 2022/12/04 21:49:48 by yushimom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*save[257];
	char		*line;

	line = NULL;
	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save[fd])
	{
		save[fd] = (char *)malloc(1);
		if (!save[fd])
			return (NULL);
		save[fd][0] = 0;
	}
	save[fd] = read_and_save(fd, &save[fd]);
	if (!save[fd])
		return (NULL);
	line = get_line(save[fd]);
	save[fd] = get_next_save(save[fd]);
	return (line);
}

char	*read_and_save_b(int fd, char **save)
{
	ssize_t	size;
	char	*buf;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
	{
		free (*save);
		*save = NULL;
		return (NULL);
	}
	size = 1;
	while (size > 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
			return (ft_free(buf, *save));
		buf[size] = '\0';
		*save = ft_strjoin(*save, buf);
		if (!*save)
			return (ft_free(buf, *save));
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (*save);
}

char	*get_line_b(char *save)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = ft_substr(save, 0, i + 1);
	if (!line)
	{
		free (save);
		save = NULL;
		return (NULL);
	}
	if (save[i] && save[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*get_next_save_b(char *save)
{
	int		i;
	char	*tmp;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	tmp = ft_substr(save, i + 1, ft_strlen(save) - i);
	free (save);
	if (!tmp)
	{
		save = NULL;
		return (NULL);
	}
	save = tmp;
	return (save);
}

void	*ft_free_b(char *buf, char *save)
{
	free(buf);
	buf = NULL;
	free(save);
	save = NULL;
	return (NULL);
}
