/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:35:40 by arabiai           #+#    #+#             */
/*   Updated: 2023/03/04 13:52:11 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_infos *data)
{
	push_chunks_to_b(data);
	push_chunks_back_to_a(data);
}

void	sort_2(t_infos *data)
{
	t_deque	*temp_a;

	temp_a = data->a;
	if (is_sorted(temp_a) == 0)
		sa(data, 1);
}

void	sort_3(t_infos *data)
{
	t_node	*temp;
	t_node	*middle;
	t_node	*last;

	temp = data->a->head;
	middle = temp->next;
	last = data->a->tail;
	if (temp->number > middle->number)
	{
		if (temp->number > last->index)
			ra(data, 1);
		if (!is_sorted(data->a))
			sa(data, 1);
	}
	else
	{
		if (!is_sorted(data->a))
			rra(data, 1);
		if (!is_sorted(data->a))
			sa(data, 1);
	}
}

void	sort_5(t_infos *data)
{
	t_deque	*a;
	t_deque	*b;

	a = data->a;
	b = data->b;
	get_min_to_the_top(data);
	get_min_to_the_top(data);
	sort_3(data);
	if (!is_sorted(b))
	{
		pa(data);
		pa(data);
	}
	else
	{
		sb(data, 1);
		pa(data);
		pa(data);
	}
}

void	sort_the_stack(t_infos *data)
{
	if (data->stack_size == 1 || data->stack_size == 0)
		return ;
	else if (data->stack_size == 2)
		sort_2(data);
	else if (data->stack_size == 3)
		sort_3(data);
	else if (data->stack_size == 5 || data->stack_size == 4)
		sort_5(data);
	else if (data->stack_size > 5)
		sort(data);
}
