/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:53:05 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/10 13:13:21 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../get_next_line/get_next_line.h"
#include "../ft_printf/ft_printf.h"
#include "../libft_utils/libft_utils.h"

// typedef struct s_stack
// {
// 	int				number;
// 	struct s_stack	*next;
// 	struct s_stack	*previous;
// }					t_stack;

typedef struct s_infos
{
	int		stack_size;
	t_stack *a;
	t_stack *b; 
}			t_infos;
/* parsing */
int check_argv(char *str);
void push_argvi_to_a(char *str, t_infos *data);
void push_to_a(int x, t_infos *infos);

#endif