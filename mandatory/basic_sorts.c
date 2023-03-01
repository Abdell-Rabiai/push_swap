/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:35:40 by arabiai           #+#    #+#             */
/*   Updated: 2023/03/01 19:01:59 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_more_than_5(t_infos *data)
{
	push_chunks_to_b(data);
	// push_chunks_back_to_a(data);
}

bool	is_sorted(t_deque *a)
{
	t_node	*temp;

	temp = a->head;
	while (temp->next)
	{
		if (temp->index > temp->next->index)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	sort_2(t_infos *data)
{
	t_deque	*temp_a;

	temp_a = data->a;
	if (is_sorted(temp_a) == 0)
		sa(data, 1);
}

void	sort_the_stack(t_infos *data)
{
	if (data->stack_size == 1 || data->stack_size == 0)
		return ;
	else if (data->stack_size == 2)
		sort_2(data);
	else if (data->stack_size > 5)
		sort_more_than_5(data);
}
