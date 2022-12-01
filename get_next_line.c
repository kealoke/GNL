/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushimom <yushimom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:36:18 by yushimom          #+#    #+#             */
/*   Updated: 2022/11/29 21:25:53 by yushimom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_save(char *save)
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
	free(save);
	if (!tmp)
	{
		free(tmp);
		tmp = NULL;
		save = NULL;
	}
	else
		save = tmp;
	return (save);
}

char	*get_line(char *save)
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
		free(line);
		line = NULL;
		return (NULL);
	}
	if (save[i] && save[i] == '\n')
		line[i++] = '\n';
	return (line);
}

ssize_t	ft_read(int fd, char *buf, ssize_t size)
{
	size = read(fd, buf, BUFFER_SIZE);
	if (size == -1)
	{
		buf = NULL;
		return (0);
	}
	return (size);
}

char	*read_and_save(int fd, char **save)
{
	char	*buf;
	ssize_t	size;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (!*save)
	{
		*save = (char *)malloc(1);
		if (!*save)
			return (NULL);
		*save[0] = 0;
	}
	size = 1;
	while (size > 0)
	{
		size = ft_read(fd, buf, size);
		buf[size] = '\0';
		*save = ft_strjoin(*save, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	buf = NULL;
	return (*save);
}

char	*get_next_line(int fd)
{
	static char	*save[257];
	char		*line;

	line = NULL;
	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = read_and_save(fd, &save[fd]);
	line = get_line(save[fd]);
	save[fd] = get_next_save(save[fd]);
	return (line);
}

// int main(int argc, char const *argv[])
// {
// 	int		fd;
// 	char	*str;

// 	fd = open("test.txt", O_RDONLY);
// 	while (1)
// 	{
// 		str = get_next_line(fd);
// 		printf("%s", str);
// 		if (!str)
// 			break ;
// 		free(str);
// 	}
// 	close(fd);
// 	return (0);
// }
