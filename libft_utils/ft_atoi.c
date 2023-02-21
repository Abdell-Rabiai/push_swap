/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:48:25 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/21 14:57:01 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

long	ft_atoi(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (is_whitespace(*str))
		str++;
	if (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
		sign *= (-1);
	str++;
	}
	if (!(*str))
		return (UINT_MAX);
	while (*str)
	{
		result *= 10;
		result += *str - '0';
		if ((result > 2147483647 && sign == 1) || result * (-1) < INT_MIN
			|| !ft_isdigit(*str))
			return (UINT_MAX);
		str++;
	}
	return (result * (sign));
}
