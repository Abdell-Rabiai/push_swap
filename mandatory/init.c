/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:11:20 by arabiai           #+#    #+#             */
/*   Updated: 2023/03/03 18:10:34 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_data(t_infos *data)
{
	data->a = (t_deque *)malloc(sizeof(t_deque));
	data->b = (t_deque *)malloc(sizeof(t_deque));
	data->a->head = NULL;
	data->a->tail = NULL;
	data->a->size = 0;
	data->b->head = NULL;
	data->b->tail = NULL;
	data->b->size = 0;
}

void	fill_a(t_infos *data)
{
	int		i;
	t_node	*temp;

	i = 0;
	while (i < data->stack_size)
	{
		temp = ft_new_node(data->numbers[i], -1);
		ft_push_rear(data->a, temp);
		i++;
	}
	return_max(data->a);
	return_min(data->a);
}

void	print_ab(t_infos *data)
{
	t_node	*temp_a;
	t_node	*temp_b;

	temp_a = data->a->head;
	temp_b = data->b->head;
	while (temp_a != NULL && temp_b != NULL)
	{
		ft_printf(" : a* %d : [index : %d]              b* %d\n",
			temp_a->number, temp_a->index, temp_b->number);
		temp_a = temp_a->next;
		temp_b = temp_b->next;
	}
	while (temp_a != NULL)
	{
		ft_printf(" : a* %d : [index : %d]\n", temp_a->number,
			temp_a->index);
		temp_a = temp_a->next;
	}
	while (temp_b != NULL)
	{
		ft_printf(" : b* %d : [index : %d]\n", temp_b->number,
			temp_b->index);
		temp_b = temp_b->next;
	}
}