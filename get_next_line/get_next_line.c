/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:24:56 by arabiai           #+#    #+#             */
/*   Updated: 2023/03/03 17:53:23 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *src)
{
	char	*copy;
	size_t	i;

	i = 0;
	copy = (char *)malloc(ft_strlen((char *)src) * sizeof(char) + 1);
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, (char *)src, ft_strlen((char *)src) + 1);
	return (copy);
}

static int	is_there_newline(char *str, int *newline)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			*newline = i;
			return (1);
		}
		i++;
	}
	return (0);
}

static char	*read_the_rest(char *saved_string, int newline_index)
{
	char	*str;
	int		i;
	int		j;

	if (!saved_string)
		return (NULL);
	if (saved_string[newline_index] == '\0')
	{
		free(saved_string);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char)
			* (ft_strlen(saved_string) - newline_index));
	if (!str)
		return (NULL);
	j = newline_index + 1;
	i = 0;
	while (saved_string[j] != '\0')
		str[i++] = saved_string[j++];
	str[i] = '\0';
	free(saved_string);
	return (str);
}

static char	*read_file(int fd, char *saved_string)
{
	char	*buffer;
	int		nbytes;
	int		newline_index;

	newline_index = 0;
	nbytes = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (!is_there_newline(saved_string, &newline_index) && nbytes != 0)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(buffer);
			free(saved_string);
			return (NULL);
		}
		buffer[nbytes] = '\0';
		saved_string = ft_strjoin1(saved_string, buffer);
	}
	return (free(buffer), saved_string);
}

char	*get_next_line(int fd)
{
	static char	*saved_string;
	char		*line;
	int			newline_index;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!saved_string)
		saved_string = ft_strdup("");
	saved_string = read_file(fd, saved_string);
	if (!saved_string)
		return (NULL);
	if (is_there_newline(saved_string, &newline_index))
	{
		line = ft_substr(saved_string, 0, newline_index + 1);
		saved_string = read_the_rest(saved_string, newline_index);
	}
	else
	{
		newline_index = ft_strlen(saved_string);
		line = ft_substr(saved_string, 0, newline_index + 1);
		saved_string = read_the_rest(saved_string, newline_index);
	}
	return (line);
}
