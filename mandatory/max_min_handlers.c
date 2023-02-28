/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:44:56 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/28 18:46:51 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	return_max(t_deque *a)
{
	int		max_num;
	t_node	*temp;

	temp = a->head;
	max_num = temp->number;
	while (temp->next)
	{
		if (max_num < temp->next->number)
			max_num = temp->next->number;
		temp = temp->next;
	}
	a->max = max_num;
	return (max_num);
}

int	return_min(t_deque *a)
{
	int		min_num;
	t_node	*temp;

	temp = a->head;
	min_num = temp->number;
	while (temp->next)
	{
		if (min_num > temp->next->number)
			min_num = temp->next->number;
		temp = temp->next;
	}
	a->min = min_num;
	return (min_num);
}

t_node	*get_max_node(t_deque *a)
{
	t_node	*max_num;
	t_node	*temp;

	temp = a->head;
	max_num = temp;
	while (temp->next)
	{
		if (max_num->number < temp->next->number)
			max_num = temp->next;
		temp = temp->next;
	}
	return (max_num);
}

t_node	*get_before_max_node(t_deque *a)
{
	t_node	*before_max_num;
	t_node	*temp;
	t_node	*max_num;

	temp = a->head;
	max_num = get_max_node(a);
	before_max_num = temp;
	if (max_num->number == a->head->number)
		before_max_num = temp->next;
	while (temp->next)
	{
		if (before_max_num->number < temp->next->number
			&& temp->next->number < max_num->number)
			before_max_num = temp->next;
		temp = temp->next;
	}
	return (before_max_num);
}
