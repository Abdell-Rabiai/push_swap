/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:53:01 by arabiai           #+#    #+#             */
/*   Updated: 2023/03/04 14:12:15 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_infos *data, bool print)
{
	t_node	*temp_first;

	if (data->a->size <= 1)
		return ;
	temp_first = ft_pop_front(data->a);
	ft_push_rear(data->a, temp_first);
	if (print)
		ft_printf(STDOUT_FILENO, "ra\n");
}

void	rb(t_infos *data, bool print)
{
	t_node	*temp_first;

	if (data->b->size <= 1)
		return ;
	temp_first = ft_pop_front(data->b);
	ft_push_rear(data->b, temp_first);
	if (print)
		ft_printf(STDOUT_FILENO, "rb\n");
}

void	rr(t_infos *data)
{
	if (data->a->size <= 1 && data->b->size <= 1)
		return ;
	ra(data, 0);
	rb(data, 0);
	ft_printf(STDOUT_FILENO, "rr\n");
}

void	rra(t_infos *data, bool print)
{
	t_node	*temp_last;

	if (data->a->size <= 1)
		return ;
	temp_last = ft_pop_rear(data->a);
	ft_push_front(data->a, temp_last);
	if (print)
		ft_printf(STDOUT_FILENO, "rra\n");
}

void	rrb(t_infos *data, bool print)
{
	t_node	*temp_last;

	if (data->b->size <= 1)
		return ;
	temp_last = ft_pop_rear(data->b);
	ft_push_front(data->b, temp_last);
	if (print)
		ft_printf(STDOUT_FILENO, "rrb\n");
}
