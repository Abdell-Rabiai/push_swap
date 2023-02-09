/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:06:21 by arabiai           #+#    #+#             */
/*   Updated: 2023/01/27 18:31:41 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <fcntl.h>

# define SPECIFIER "%scdiuxXp"

int		ft_printf(const char *string_format, ...);

void	ft_putchar_fd_count(char c, int fd, int *count);
size_t	ft_strlen(const char *str);
void	ft_putnbr_base(int n, int fd, int *count, char *base);
void	ft_putnbr_fd_uns_count(unsigned int n, int fd, int *count);
void	ft_putstr_fd_count(char *s, int fd, int *count);

#endif
