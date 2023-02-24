/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:48:41 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/23 14:21:32 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_infos *data, bool print)
{
	int	temp_first;
	int	temp_second;

	if (data->a->size <= 1)
		return;
	temp_first = ft_pop_front(data->a);
	temp_second = ft_pop_front(data->a);
	ft_push_front(data->a, temp_first);
	ft_push_front(data->a, temp_second);
	if (print)
		ft_printf("sa\n");
}

void sb(t_infos *data, bool print)
{
	int	temp_first;
	int	temp_second;

	if (data->b->size <= 1)
		return;
	temp_first = ft_pop_front(data->b);
	temp_second = ft_pop_front(data->b);
	ft_push_front(data->b, temp_first);
	ft_push_front(data->b, temp_second);
	if (print)
		ft_printf("sb\n");
}

void	ss(t_infos *data)
{
	sa(data, 0);
	sb(data, 0);
	ft_printf("ss\n");
}

void pb(t_infos *data)
{
	int	temp_first_a;

	if (data->a->size == 0)
		return;
	temp_first_a = ft_pop_front(data->a);
	ft_push_front(data->b, temp_first_a);
	ft_printf("pb\n");
}

void pa(t_infos *data)
{
	int	temp_first_b;

	if (data->b->size == 0)
		return;
	temp_first_b = ft_pop_front(data->b);
	ft_push_front(data->a, temp_first_b);
	ft_printf("pa\n");
}

void ra(t_infos *data, bool print)
{
	int	temp_first;

	if (data->a->size <= 1)
			return ;
	temp_first = ft_pop_front(data->a);
	ft_push_rear(data->a, temp_first);
	if (print)
		ft_printf("ra\n");		
}

void rb(t_infos *data, bool print)
{
	int	temp_first;

	if (data->b->size <= 1)
			return ;
	temp_first = ft_pop_front(data->b);
	ft_push_rear(data->b, temp_first);
	if (print)
		ft_printf("rb\n");		
}

void rr(t_infos *data)
{
	if (data->a->size <= 1 && data->b->size <= 1)
		return ;
	ra(data, 0);
	rb(data, 0);
	ft_printf("rr\n");
}

void rra(t_infos *data, bool print)
{
	int	temp_last;

	if (data->a->size <= 1)
		return;
	temp_last = ft_pop_rear(data->a);
	ft_push_front(data->a, temp_last);
	if (print)
		ft_printf("rra\n");	
}

void rrb(t_infos *data, bool print)
{
	int	temp_last;

	if (data->b->size <= 1)
		return;
	temp_last = ft_pop_rear(data->b);
	ft_push_front(data->b, temp_last);
	if (print)
		ft_printf("rrb\n");	
}

void rrr(t_infos *data)
{
	if (data->a->size <= 1 && data->b->size <= 1)
		return ;
	rra(data, 0);
	rrb(data, 0);
	ft_printf("rrr\n");
}