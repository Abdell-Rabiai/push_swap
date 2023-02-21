/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:48:38 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/21 19:25:09 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_data(t_infos *data)
{
	data->a->head->next = NULL;
	data->a->head->previous = NULL;
	data->a->head->number = 0;
	
	// data->a->tail->next = NULL;
	// data->a->tail->previous = NULL;
	// data->a->tail->number = 0;
	
	// data->b->head->next = NULL;
	// data->b->head->previous = NULL;
	// data->b->head->number = 0;
	
	// data->b->tail->next = NULL;
	// data->b->tail->previous = NULL;
	// data->b->tail->number = 0;
	
	data->numbers = NULL;
	data->stack_size = 0;
}

void fill_b(t_infos *data)
{
	int i;

	i = 0;
	while (i < data->stack_size)
	{
		ft_push_rear(data->a, data->numbers[i]);
		i++;
	}
}

void print_a(t_infos *data)
{
	t_node *temp;

	temp = data->a->head;
	while (temp != NULL)
	{
		ft_printf("%d\n", temp->number);
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	t_infos	data;

	initialize_data(&data);
	parse_arguments(argc, argv, &data);
	fill_b(&data);
	print_a(&data);
}
