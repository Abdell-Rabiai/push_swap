/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:48:41 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/28 18:54:29 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_infos *data, bool print)
{
	t_node	*temp_first;
	t_node	*temp_second;

	if (data->a->size <= 1)
		return ;
	temp_first = ft_pop_front(data->a);
	temp_second = ft_pop_front(data->a);
	ft_push_front(data->a, temp_first);
	ft_push_front(data->a, temp_second);
	if (print)
		printf("sa\n");
}

void	sb(t_infos *data, bool print)
{
	t_node	*temp_first;
	t_node	*temp_second;

	if (data->b->size <= 1)
		return ;
	temp_first = ft_pop_front(data->b);
	temp_second = ft_pop_front(data->b);
	ft_push_front(data->b, temp_first);
	ft_push_front(data->b, temp_second);
	if (print)
		printf("sb\n");
}

void	ss(t_infos *data)
{
	sa(data, 0);
	sb(data, 0);
	printf("ss\n");
}

void	pb(t_infos *data)
{
	t_node	*temp_first_a;

	if (data->a->size == 0)
		return ;
	temp_first_a = ft_pop_front(data->a);
	ft_push_front(data->b, temp_first_a);
	printf("pb\n");
}

void	pa(t_infos *data)
{
	t_node	*temp_first_b;

	if (data->b->size == 0)
		return ;
	temp_first_b = ft_pop_front(data->b);
	ft_push_front(data->a, temp_first_b);
	printf("pa\n");
}
