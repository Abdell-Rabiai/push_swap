/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:48:12 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/25 17:50:27 by arabiai          ###   ########.fr       */
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
			while (temp->number != data->a->head->number)
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

void get_node_to_top_of_b(t_infos *data, t_node *n)
{
	t_node *temp;
	int		midian;

	midian = data->b->size / 2;
	temp = data->b->head;
	int num;
	while (temp)
	{
		if (temp->number == n->number && temp->indice >= midian)
		{
			num = temp->number;
			while (num != data->b->head->number)
				rb(data, 1);
			break;
		}
		else if(temp->number == n->number && temp->indice < midian)
		{
			num = temp->number;
			while (num != data->b->head->number)
				rrb(data, 1);
			break;
		}
		else 
			temp = temp->next;
	}
	
}

void handle_top_of_b(t_infos *data, int mid)
{
	t_deque *b;
	t_node *t;

	b = data->b;
	t = b->head;
	index_the_stack(b);
	if (t->indice < mid)
		get_node_to_top_of_b(data, t);
}

void push_chunks_to_b(t_infos *data, int start_of_chunk, int end_of_chunk)
{
	t_deque *a;
	t_node *temp_a;
	int x;
	int mid;

	a = data->a;
	temp_a = a->head;
	x = 0;
	mid = start_of_chunk + end_of_chunk/2;
	while (temp_a)
	{
		x = 0;
		if (temp_a->index == start_of_chunk && start_of_chunk != end_of_chunk)
		{
			get_node_to_top_of_a(data, temp_a);
			pb(data);
			handle_top_of_b(data, mid);
			start_of_chunk++;
			x = 1;
			temp_a = a->head;
		}
		if (x == 0)
			temp_a = temp_a->next;
	}
}

void push_chunks_back_to_a(t_infos *data)
{
	t_deque *b;
	t_node *temp_b;
	int length;
	// int	i;
	int x;

	b = data->b;
	temp_b = b->head;
	length = b->size - 1;
	// printf("HELLO %d WOLRD \n",length);
	// i = 0;
	while (temp_b)
	{
		x = 0;
		if (temp_b->index == length)
		{
			get_node_to_top_of_b(data, temp_b);
			pa(data);
			length--;
			x = 1;
			temp_b = b->head;
		}
		if (x == 0)
			temp_b = temp_b->next;
	}
}

void sort_more_than_5(t_infos *data)
{
	int start_of_chunk;
	int end_of_chunk;
	int length;
	int increment;

	length = data->stack_size;
	start_of_chunk = 0;
	increment = length / 5;
	end_of_chunk = increment;

	while (length >= 0)
	{
		push_chunks_to_b(data, start_of_chunk, end_of_chunk);
		start_of_chunk = start_of_chunk + increment;
		end_of_chunk = end_of_chunk + increment;
		length = length - increment;
	}
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
	else if (data->stack_size >= 5)
	    sort_more_than_5(data);
	// else if (data->stack_size == 5)
	//     sort_5(data);
	// else
	// 	sort(data):
}
