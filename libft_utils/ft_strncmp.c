/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:19:06 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/21 11:58:10 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while ((*(ss1 + i) || *(ss2 + i)) && i < n)
	{
		if (*(ss1 + i) != *(ss2 + i))
			return (*(ss1 + i) - *(ss2 + i));
		else
			i++;
	}
	return (0);
}
