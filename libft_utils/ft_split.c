/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:43:14 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/20 18:09:25 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"

int	ft_how_many_words(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			i++;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

char	**ft_free_split(char **strings)
{
	int	i;

	i = 0;
	while (strings[i] != 0)
	{
		free(strings[i]);
		i++;
	}
	free(strings);
	return (NULL);
}

int	ft_get_length_of_word(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

char	*return_the_first_word(const char *s, char c)
{
	int		i;
	int		length;
	char	*word;

	i = 0;
	length = ft_get_length_of_word(s, c);
	word = (char *)malloc(sizeof(char) * length + 1);
	if (!word)
		return (NULL);
	while (i < length)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**strings;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	strings = (char **)malloc(sizeof(char *) * (ft_how_many_words(s, c) + 1));
	if (!strings)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			strings[i] = return_the_first_word(s, c);
			if (!strings[i])
				return (ft_free_split(strings));
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	strings[i] = 0;
	return (strings);
}
