/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:48:25 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/21 14:04:52 by arabiai          ###   ########.fr       */
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

int	get_index_base(int c, int base)
{
	char	*str;
	char	*str2;
	int		i;

	str = "0123456789abcdef";
	str2 = "0123456789ABCDEF";
	i = 0;
	while (i < base)
	{
		if (c == str[i] || c == str2[i])
			return (i);
		i++;
	}
	return (-1);
}

// int	t_atohex(const char *str)
// {
// 	int			sign;
// 	long double	res;

// 	sign = 1;
// 	res = 0;
// 	while (*str && ft_iswhitespace(*str))
// 		str++;
// 	if (*str == '-')
// 	{
// 		sign *= -1;
// 		str++;
// 	}
// 	else if (*str == '+')
// 		str++;
// 	while (*str)
// 	{
// 		res *= 16;
// 		res += get_index_base(*str, 16);
// 		str++;
// 	}
// 	return (res * sign);
// }
