/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:48:12 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/27 21:55:31 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int return_max(t_deque *a)
{
	int max_num;
	t_node *temp;

	temp = a->head;
	max_num = temp->number;
	while (temp->next != NULL)
	{
		if (max_num < temp->next->number)
			max_num = temp->next->number;
		temp = temp->next;
	}
	a->max = max_num;
	return max_num;
}

int return_min(t_deque *a)
{
	int min_num;
	t_node *temp;

	temp = a->head;
	min_num = temp->number;
	while (temp->next != NULL)
	{
		if (min_num > temp->next->number)
			min_num = temp->next->number;
		temp = temp->next;
	}
	a->min = min_num;
	return min_num;
}

int return_min_for_indexing(t_deque *a)
{
	int min_num;
	t_node *temp;

	temp = a->head;
	min_num = temp->number;
	while (temp)
	{
		if (temp->index == -1)
			min_num = temp->number;
		temp = temp->next;
	}
	temp = a->head;
	while (temp)
	{
		if (min_num > temp->number && temp->index == -1)
			min_num = temp->number;
		temp = temp->next;
	}
	return min_num;
}

// void index_the_stack(t_deque *a)
// {
// 	t_node	*temp_a;
// 	int		i;
// 	int 	b;
// 	int		min;

// 	temp_a = a->head;
// 	i = 0;
// 	while (temp_a != NULL)
// 	{
// 		b = 0;
// 		min = return_min_for_indexing(a);
// 		printf("{min -> %d number %d}\n", min, temp_a->number);
// 		if (temp_a->number == min && temp_a->index == -1)
// 		{
// 			printf("before (%d == [%d])\n", min, temp_a->index);
// 			temp_a->index = i++;
// 			printf("after (%d == [%d])\n", min, temp_a->index);
// 			temp_a = a->head;
// 			b = 1;
// 		}
// 		if (b == 0)
// 			temp_a = temp_a->next;
// 	}
// }

void indice_the_stack(t_deque *a)
{
	t_node *temp;
	int		i;

	i = 0;
	temp = a->head;
	while (temp)
	{
		temp->indice = i;
		i++;
		temp = temp->next;
	}

}

void index_the_stack(t_deque *a) // index the stack using two nested while loops
{
	t_node	*temp_a;
	t_node	*temp_b;
	int		i;

	temp_a = a->head;
	i = 0;
	while (temp_a != NULL)
	{
		temp_b = a->head;
		while (temp_b != NULL)
		{
			if (temp_a->number > temp_b->number)
				i++;
			temp_b = temp_b->next;
		}
		temp_a->index = i;
		i = 0;
		temp_a = temp_a->next;
	}
	indice_the_stack(a);
}

bool is_sorted(t_deque *a)
{
	t_node *temp;

	temp = a->head;
	while (temp)
	{
		if (temp->index != temp->number)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void sort_2(t_infos *data)
{
	t_deque *temp_a;

	temp_a = data->a;
	if(is_sorted(temp_a) == 0)
		sa(data, 1);
}

void get_node_to_top_of_a(t_infos *data, t_node *n)
{
	t_node *temp;
	int		midian;

	midian = data->a->size / 2;
	temp = data->a->head;
	int num;
	while (temp)
	{
		if (temp->number == n->number && temp->indice >= midian)
		{
			num = temp->number;	
			while (num != data->a->head->number)
				ra(data, 1);
			break;
		}
		else if(temp->number == n->number && temp->indice < midian)
		{
			num = temp->number;
			while (num != data->a->head->number)
				rra(data, 1);
			break;
		}
		temp = temp->next;
	}
}

void get_node_to_top_of_b(t_infos *data, int position)
{
	t_node *temp;
	int		midian;

	midian = data->b->size / 2;
	temp = data->b->head;
	while(position >= midian && position)
	{
		rrb(data, 1);
		position--;
	}
	while(position < midian && position)
	{
		rb(data, 1);
		position--;
	}
}

void push_chunks_to_b(t_infos *data) // 0 --> 4
{
	t_deque *a;
	t_deque *b;

	int c;
	int end_of_chunk = data->stack_size/5;
	int	mid;
	int	mid_fix;

	a = data->a;
	b = data->b;
	c = end_of_chunk;
	mid = end_of_chunk/2;
	mid_fix = mid;
	while (a->head)
	{
		while (a->head && b->size != end_of_chunk)
		{
			if (a->head->index <= end_of_chunk)
			{
				if (a->head->index < mid)
					pb(data);
				else
				{
					pb(data);
					rb(data, 1);
				}
			}
			else
				ra(data, 1);
		
		}
		end_of_chunk += c;
		mid = end_of_chunk - mid_fix;	
	}
}
/*
count = chunk;
while (stack_a)
{
	while (size(stack_b) < chunk)
	{
		if (stack_a->data < chunk)
		[
			if (stack_a->index < chunk/2)
				pb;
			else
				pb;
				rb;
		]
		else
			ra;
	}
	chunk += count;
}
*/

int return_position(t_deque *a, t_node *temp_b)
{
	if (!a || !temp_b || !a->head)
        return (-1);
	t_node *temp;
	int		i;

	i = 0;
	temp = a->head;
	while (temp)
	{
		if (temp->number == temp_b->number)
			return (i);
		i++;
		temp = temp->next;
	}
	return (-1);
}
t_node *get_max_node(t_deque *a)
{
	t_node *max_num;
	t_node *temp;

	temp = a->head;
	max_num = temp;
	while (temp->next != NULL)
	{
		if (max_num->number < temp->next->number)
			max_num = temp->next;
		temp = temp->next;
	}
	return max_num;
}

t_node *get_before_max_node(t_deque *a)
{
	t_node *before_max_num;
	t_node *temp;
	t_node *max_num;

	temp = a->head;
	max_num = get_max_node(a);
	before_max_num = temp;
	if (max_num->number == a->head->number)
		before_max_num = temp->next;
	while (temp->next != NULL)
	{
		if (before_max_num->number < temp->next->number && temp->next->number < max_num->number)
			before_max_num = temp->next;
		temp = temp->next;
	}
	return before_max_num;
}

int get_number_of_instructions(t_deque *a, t_node *temp_b)
{
	int i;
	int position;

	i = 0;
	position = return_position(a, temp_b);
	if (position > ft_get_size(a)/2 && position)
		i = ft_get_size(a) - position;
	if (position <= ft_get_size(a)/2 && position)
		i = position;
	return (0);
}

void push_chunks_back_to_a(t_infos *data)
{
	t_deque *b;
	t_node *temp_b;
	int length;

	b = data->b;
	temp_b = b->head;
	length = b->size - 1;
	while (data->b->head)
	{
		if (get_number_of_instructions(data->b, get_max_node(data->b)) >= get_number_of_instructions(data->b, get_before_max_node(data->b)))
		{
			while (return_position(data->b, get_max_node(data->b)) > data->b->size/2 && return_position(data->b, get_max_node(data->b)))
				rrb(data, 1);
			while (return_position(data->b, get_max_node(data->b)) <= data->b->size/2 && return_position(data->b, get_max_node(data->b)))
				rb(data, 1);
			if (!return_position(data->b, get_max_node(data->b)) && data->b)
				pa(data);

		}
		else
		{
			while (return_position(data->b, get_before_max_node(data->b)) > data->b->size/2 && return_position(data->b, get_before_max_node(data->b)))
				rrb(data, 1);
			while (return_position(data->b, get_before_max_node(data->b)) <= data->b->size/2 && return_position(data->b, get_before_max_node(data->b)))
				rb(data, 1);
			if (!return_position(data->b, get_before_max_node(data->b)))
				pa(data);

			while (return_position(data->b, get_max_node(data->b)) > data->b->size/2 && return_position(data->b, get_max_node(data->b)))
				rrb(data, 1);
			while (return_position(data->b, get_max_node(data->b)) <= data->b->size/2 && return_position(data->b, get_max_node(data->b)))
				rb(data, 1);
			if (!return_position(data->b, get_max_node(data->b)))
				{pa(data);
				sa(data, 1);}
		}
		
	}
	// printf("GOOGLE	\n");
}


void sort_more_than_5(t_infos *data)
{
	push_chunks_to_b(data);
	push_chunks_back_to_a(data);
}

void sort_the_stack(t_infos *data)
{
	// t_deque *temp_a;

	// temp_a = data->a;
	if (data->stack_size == 1 || data->stack_size == 0)
		return ;
	else if (data->stack_size == 2)
		sort_2(data);
	else if (data->stack_size > 5)
	    sort_more_than_5(data);
	// else if (data->stack_size == 5)
	//     sort_5(data);
	// else
	// 	sort(data):
}
