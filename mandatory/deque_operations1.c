/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_operations1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:33:31 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/28 18:55:40 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_rear(t_deque *deck)
{
	if (deck->tail == NULL)
		return (INT_MAX);
	return (deck->tail->number);
}

int	ft_get_front(t_deque *deck)
{
	if (deck->head == NULL)
		return (INT_MAX);
	return (deck->head->number);
}

int	ft_is_empty(t_deque *deck)
{
	if (deck->head == NULL)
		return (1);
	else
		return (0);
}

int	ft_get_size(t_deque *deck)
{
	return (deck->size);
}
