/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:26:19 by arabiai           #+#    #+#             */
/*   Updated: 2023/01/27 18:33:57 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
	int     length;

	length = 0;
	while (*str)
	{
			length++;
			str++;
	}
	return (length);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (s[0] == '\0')
		return (NULL);
	if (start >= ft_strlen(s))
		return (malloc(1));
	if (ft_strlen(s) <= start + len)
		substr = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (s[start] && i < len)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (i < (dstsize - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dest_length;
	size_t	src_length;

	i = 0;
	if ((!dst && !dstsize))
		return (0);
	dest_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	if (dstsize <= dest_length)
		return (src_length + dstsize);
	while (i < dstsize - dest_length - 1 && src[i] != '\0')
	{
		dst[i + dest_length] = src[i];
		i++;
	}
	dst[i + dest_length] = '\0';
	return (dest_length + src_length);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
        char    *strjoin;
        size_t  i;
        size_t  len_total;

        if (!s1 || !s2)
                return (NULL);
        i = 0;
        len_total = ft_strlen(s1) + ft_strlen(s2);
        strjoin = (char *)malloc(sizeof(char) * (len_total + 1));
        if (!strjoin)
                return (NULL);
        ft_strlcpy(strjoin, s1, ft_strlen(s1) + 1);
        ft_strlcat(strjoin, s2, len_total + 1);
        free((char *)s1);
        return (strjoin);
}