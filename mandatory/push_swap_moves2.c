/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:54:34 by arabiai           #+#    #+#             */
/*   Updated: 2023/03/04 14:12:36 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_infos *data)
{
	if (data->a->size <= 1 && data->b->size <= 1)
		return ;
	rra(data, 0);
	rrb(data, 0);
	ft_printf(STDOUT_FILENO, "rrr\n");
}

void	ft_free_stack(t_deque *a)
{
	t_node	*temp;
	t_node	*t;

	temp = a->head;
	while (temp)
	{
		t = temp->next;
		free(temp);
		temp = t;
	}
	free(a);
}

void	ft_free_everything(t_infos *data)
{
	ft_free_stack(data->a);
	ft_free_stack(data->b);
	free(data->numbers);
}
