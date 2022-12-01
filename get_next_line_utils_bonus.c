/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushimom <yushimom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:16:48 by yushimom          #+#    #+#             */
/*   Updated: 2022/12/01 14:06:01 by yushimom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *src, int c)
{
	while (*src != '\0')
	{
		if (*src == (char)c)
			return ((char *)src);
		src++;
	}
	if (!c)
		return ((char *)src);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	sub_len;

	if (!s)
		return (NULL);
	if (len == 0 || ft_strlen(s) < start)
	{
		substr = (char *)malloc(1);
		return (substr);
	}
	sub_len = ft_strlen(s + start);
	if (sub_len < len)
		len = sub_len;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (*s != '\0' && len-- > 0)
	{
		substr[i++] = s[start++];
	}
	substr[i] = '\0';
	return (substr);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	slen = ft_strlen(src);
	if (!dst && src && dstsize == 0)
		return (slen);
	if (dstsize <= 0)
		return (slen);
	i = 0;
	while (dst[i] != '\0')
		i++;
	dlen = ft_strlen(dst);
	if (dstsize <= dlen)
		return (dstsize + slen);
	j = 0;
	while ((src[j] != '\0' || src[j]) && dstsize - dlen - 1 > j)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (dlen + slen);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_s;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_s = (char *)malloc(len_s1 + len_s2 + 1);
	if (!new_s)
		return (NULL);
	i = 0;
	while ((len_s1) > i && s1[i] != '\0')
	{
		new_s[i] = s1[i];
		i++;
	}
	new_s[i] = '\0';
	ft_strlcat(new_s, s2, len_s1 + len_s2 + 1);
	free (s1);
	s1 = new_s;
	return (s1);
}
