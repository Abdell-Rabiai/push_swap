/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:23:27 by arabiai           #+#    #+#             */
/*   Updated: 2023/03/04 14:06:03 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd_count(char c, int fd, int *count)
{
	write(fd, &c, 1);
	(*count)++;
}

void	ft_putnbr_base(int n, int fd, int *count, char *base)
{
	size_t	base_len;
	long	nb;

	base_len = ft_strlen(base);
	nb = n;
	if (base_len == 16)
		nb = (unsigned int)n;
	if (nb < 0 && base_len == 10)
	{
		ft_putchar_fd_count('-', fd, count);
		nb *= -1;
	}
	if (nb < (int)base_len)
		ft_putchar_fd_count(base[nb % base_len], fd, count);
	else
	{
		ft_putnbr_base(nb / base_len, fd, count, base);
		ft_putnbr_base(nb % base_len, fd, count, base);
	}
}

void	ft_putnbr_fd_uns_count(unsigned int n, int fd, int *count)
{
	if (n < 10)
		ft_putchar_fd_count(n + '0', fd, count);
	else
	{
		ft_putnbr_fd_uns_count(n / 10, fd, count);
		ft_putnbr_fd_uns_count(n % 10, fd, count);
	}
}

void	ft_putstr_fd_count(char *s, int fd, int *count)
{
	if (!s)
	{
		ft_putstr_fd_count("(null)", fd, count);
		return ;
	}
	while (*s)
	{
		ft_putchar_fd_count(*s, fd, count);
		s++;
	}
}
