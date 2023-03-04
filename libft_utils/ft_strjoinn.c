/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:19:06 by arabiai           #+#    #+#             */
/*   Updated: 2023/03/04 14:47:38 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"
#include "../get_next_line/get_next_line.h"

char	*ft_strjoin0(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	len_total;

	if (!s1 || !s2)
		return (NULL);
	len_total = ft_strlen(s1) + ft_strlen(s2);
	strjoin = (char *)malloc(sizeof(char) * (len_total + 1));
	if (!strjoin)
		return (NULL);
	ft_strlcpy(strjoin, s1, ft_strlen(s1) + 1);
	ft_strlcat(strjoin, s2, len_total + 1);
	return (strjoin);
}

char	*ft_strjoinp(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	len_total;

	if (!s1 || !s2)
		return (NULL);
	len_total = ft_strlen(s1) + ft_strlen(s2);
	strjoin = (char *)malloc(sizeof(char) * (len_total + 1));
	if (!strjoin)
		return (NULL);
	ft_strlcpy(strjoin, s1, ft_strlen(s1) + 1);
	ft_strlcat(strjoin, s2, len_total + 1);
	free((char *)s1);
	free((char *)s2);
	return (strjoin);
}
