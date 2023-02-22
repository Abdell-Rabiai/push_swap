/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:48:41 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/22 17:24:08 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void swap(t_deque *deck, char type, bool print)
{
	int	temp_first;
	int	temp_second;

	if (deck->size <= 1)
		return;
	temp_first = ft_pop_front(deck);
	temp_second = ft_pop_front(deck);
	ft_push_front(deck, temp_first);
	ft_push_front(deck, temp_second);

	if (print)
	{
		if (type == 'a')
			printf("sa\n");
		else
			printf("sb\n");		
	}
}

void	swap_both(t_infos *data)
{
	swap(data->a, 'a', 0);
	swap(data->b, 'b', 0);
	printf("ss\n");
}

void push_b(t_infos *data)
{
	int	temp_first_a;

	if (data->a->size == 0)
		return;
	temp_first_a = ft_pop_front(data->a);
	ft_push_front(data->b, temp_first_a);
	printf("pb\n");
}

void push_a(t_infos *data)
{
	int	temp_first_b;

	if (data->b->size == 0)
		return;
	temp_first_b = ft_pop_front(data->b);
	ft_push_front(data->a, temp_first_b);
	printf("pa\n");
}

void rotate_up(t_deque *deck, char type, bool print)
{
	int	temp_first;

	if (deck->size <= 1)
			return ;
	temp_first = ft_pop_front(deck);
	ft_push_rear(deck, temp_first);
	if (print)
	{
		if (type == 'a')
			printf("ra\n");
		else
			printf("rb\n");		
	}
}
void rotate_up_both(t_infos *data)
{
	rotate_up(data->a, 'a', 0);
	rotate_up(data->b, 'b', 0);
	printf("rr\n");
}

void rotate_down(t_deque *deck, char type, bool print)
{
	int	temp_last;

	printf("%c |%d|\n", type, deck->size);
	if (deck->size <= 1)
		return;
	temp_last = ft_pop_rear(deck);
	ft_push_front(deck, temp_last);
	if (print)
	{
		if (type == 'a')
			printf("rra\n");
		else
			printf("rrb\n");		
	}
}
void rotate_down_both(t_infos *data)
{
	if (data->a->size <= 1 && data->b->size <= 1)
		return ;
	rotate_down(data->a, 'a', 0);
	rotate_down(data->b, 'b', 0);
	printf("rrr\n");
}