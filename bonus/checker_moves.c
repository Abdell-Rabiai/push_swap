/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:23:00 by arabiai           #+#    #+#             */
/*   Updated: 2023/03/01 17:25:04 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void    ssc(t_infos *data)
{
	sa(data, 0);
	sb(data, 0);
}

void	pbc(t_infos *data)
{
	t_node	*temp_first_a;

	if (data->a->size == 0)
		return ;
	temp_first_a = ft_pop_front(data->a);
	ft_push_front(data->b, temp_first_a);
}

void	pac(t_infos *data)
{
	t_node	*temp_first_b;

	if (data->b->size == 0)
		return ;
	temp_first_b = ft_pop_front(data->b);
	ft_push_front(data->a, temp_first_b);
}
void	rrc(t_infos *data)
{
	if (data->a->size <= 1 && data->b->size <= 1)
		return ;
	ra(data, 0);
	rb(data, 0);
}

void	rrrc(t_infos *data)
{
	if (data->a->size <= 1 && data->b->size <= 1)
		return ;
	rra(data, 0);
	rrb(data, 0);
}