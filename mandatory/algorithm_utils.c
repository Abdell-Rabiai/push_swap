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

void index_the_stack(t_deque *a) // index the stack using two nested while loops and a counter
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
}

// bool is_sorted(t_deque *a)
// {
// 	t_node *temp;

// 	temp = a->head;
// 	while (temp)
// 	{
// 		if (temp->index != temp->number)
// 			return (0);
// 		temp = temp->next;
// 	}
// 	return (1);
// }

void sort_2(t_infos *data)
{
	t_node *temp_a;

	temp_a = data->a->head;
	if(temp_a->number > temp_a->next->number)
	{
		sa(data, 1);
	}
}

void sort_the_stack(t_infos *data)
{
	t_deque *temp_a;

	temp_a = data->a;
	if (data->stack_size == 1 || data->stack_size == 0)
		return ;
	else if (data->stack_size == 2)
		sort_2(data);
	// else if (data->stack_size == 3)
	//     sort_3(data);
	// else if (data->stack_size == 5)
	//     sort_5(data);
	// else
	// 	sort(data):
}
