/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:48:12 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/25 12:55:32 by arabiai          ###   ########.fr       */
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

void index_the_stack(t_deque *a)
{
	t_node	*temp_a;
	int		i;
	int 	b;
	int		min;

	temp_a = a->head;
	i = 0;
	while (temp_a != NULL)
	{
		b = 0;
		min = return_min_for_indexing(a);
		if (temp_a->number == min && temp_a->index == -1)
		{
			temp_a->index = i++;
			temp_a = a->head;
			b = 1;
		}
		if (b == 0)
			temp_a = temp_a->next;
	}
}

// void sort_the_stack(t_infos *data)
// {
// 	t_deque *temp_a;
// 	temp_a = data->a;
// 	if (data->stack_size == 1 || data->stack_size == 0)
// 		return ;
// 	else if (data->stack_size == 2)
// 		sa(temp_a, 1);
// 	else if (data->stack_size == 3)
// 	    sort_3();
// 	else if (data->stack_size == 4)
// 	    sort_4();
// 	else if (data->stack_size == 5)
// 	    sort_5();
// 	else
// 		sort()
// }
