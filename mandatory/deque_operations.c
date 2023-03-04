/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:33:31 by arabiai           #+#    #+#             */
/*   Updated: 2023/03/04 14:47:57 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_new_node(int number, int index)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->number = number;
	new_node->next = NULL;
	new_node->previous = NULL;
	new_node->index = index;
	return (new_node);
}

void	ft_push_front(t_deque *deck, t_node *poped)
{
	if (deck->head == NULL)
	{
		deck->head = poped;
		deck->tail = poped;
	}
	else
	{
		poped->next = deck->head;
		deck->head->previous = poped;
		deck->head = poped;
	}
	deck->size++;
}

void	ft_push_rear(t_deque *deck, t_node *poped)
{
	if (deck->tail == NULL)
	{
		deck->head = poped;
		deck->tail = poped;
	}
	else
	{
		deck->tail->next = poped;
		poped->previous = deck->tail;
		deck->tail = poped;
	}
	deck->size++;
}

t_node	*ft_pop_front(t_deque *deck)
{
	t_node	*poped;
	t_node	*temp;
	int		number;

	if (deck->head == NULL)
		return (NULL);
	temp = deck->head;
	number = temp->number;
	poped = ft_new_node(number, temp->index);
	if (!poped)
		return (NULL);
	deck->head = deck->head->next;
	if (deck->head == NULL)
		deck->tail = NULL;
	else
		deck->head->previous = NULL;
	free(temp);
	deck->size--;
	return (poped);
}

t_node	*ft_pop_rear(t_deque *deck)
{
	t_node	*temp;
	t_node	*poped;
	int		number;

	if (deck->tail == NULL)
		return (NULL);
	temp = deck->tail;
	number = temp->number;
	poped = ft_new_node(number, temp->index);
	if (!poped)
		return (NULL);
	deck->tail = deck->tail->previous;
	if (deck->tail == NULL)
		deck->head = NULL;
	else
		deck->tail->next = NULL;
	free(temp);
	deck->size--;
	return (poped);
}
