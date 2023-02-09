/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:32:42 by arabiai           #+#    #+#             */
/*   Updated: 2023/01/27 18:11:54 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"

char	*ft_strrchr(const char *s, int c)
{
	int				l;
	unsigned char	cc;

	l = ft_strlen(s);
	cc = c;
	while (l > 0 && cc != *(s + l))
		l--;
	if (l == 0 && cc != *s)
		return (0);
	return ((char *)(s + l));
}
