/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:48:12 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/28 20:43:08 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_first_chunk_to_b(t_infos *data, int start_of_chunk, int end_of_chunk)
{
	t_deque *a;
	t_deque *b;

	a = data->a;
	b = data->b;
	while (a->head && b->size < end_of_chunk)
	{
		if (a->head->index < end_of_chunk)
		{
			if(a->head->index <= (start_of_chunk + end_of_chunk) / 2)
				pb(data);
			else
			{
				pb(data);
				if (!(a->head->index < end_of_chunk))
					rr(data);
				else
					rb(data, 1);
			}
		}
		else
			ra(data, 1);
	}
}

void push_chunks_to_b(t_infos *data)
{
	t_deque *a;
	t_deque *b;

	int c;
	int end_of_chunk;
	int start_of_chunk;

	a = data->a;
	b = data->b;
	start_of_chunk = 0;
	if (data->stack_size <= 100)
		end_of_chunk = (data->a->size / 5);
	if (data->stack_size > 100)
		end_of_chunk = (data->a->size / 9);
	end_of_chunk--;
	c = end_of_chunk;
	while (a->head)
	{
		push_first_chunk_to_b(data, start_of_chunk, end_of_chunk);
		end_of_chunk += c;
		start_of_chunk += c;
	}
}
void get_max_to_the_top(t_infos *data)
{
	while (return_position(data->b, get_max_node(data->b)) >= data->b->size/2 && return_position(data->b, get_max_node(data->b)))
		rrb(data, 1);
	while (return_position(data->b, get_max_node(data->b)) < data->b->size/2 && return_position(data->b, get_max_node(data->b)))
		rb(data, 1);
}

void get_before_max_to_the_top(t_infos *data)
{
	while (return_position(data->b, get_before_max_node(data->b)) >= data->b->size/2 && return_position(data->b, get_before_max_node(data->b)))
		rrb(data, 1);
	while (return_position(data->b, get_before_max_node(data->b)) < data->b->size/2 && return_position(data->b, get_before_max_node(data->b)))
		rb(data, 1);
}

void push_chunks_back_to_a(t_infos *data)
{
	while (data->b->head)
	{
		if (get_number_of_instructions(data->b, get_max_node(data->b)) <= get_number_of_instructions(data->b, get_before_max_node(data->b)))
		{	
			get_max_to_the_top(data);
			if (!return_position(data->b, get_max_node(data->b)) && data->b)
				pa(data);
		}
		else
		{
			get_before_max_to_the_top(data);
			if (!return_position(data->b, get_before_max_node(data->b)))
				pa(data);
			get_max_to_the_top(data);
			if (!return_position(data->b, get_max_node(data->b)))
			{
				pa(data);
				sa(data, 1);
			}
		}
	}
}
