/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:48:38 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/25 21:42:45 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// create a funtion that will initialize the data structure data
void initialize_data(t_infos *data)
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

void fill_a(t_infos *data)
{
	int i;
	t_node *temp;
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

void print_ab(t_infos *data)
{
	t_node *temp_a;
	t_node *temp_b;

	temp_a = data->a->head;
	temp_b = data->b->head;
	ft_printf("stack A {max : %d} {min : %d} <----> stack B\n", data->a->max, data->a->min);
	while (temp_a != NULL && temp_b != NULL)
	{
		ft_printf("%d[%d]              %d\n", temp_a->number, temp_a->index, temp_b->number);
		temp_a = temp_a->next;
		temp_b = temp_b->next;
	}
	while (temp_a != NULL)
	{
		ft_printf("%d[%d]\n", temp_a->number, temp_a->index);
		temp_a = temp_a->next;
	}
	while (temp_b != NULL)
	{
		ft_printf("               %d\n", temp_b->number);
		temp_b = temp_b->next;
	}
}

int	main(int argc, char **argv)
{
	t_infos	data;

	initialize_data(&data);
	parse_arguments(argc, argv, &data);
	fill_a(&data);
	printf("\n----------->BEFORE<----------- \n\n");
	print_ab(&data);
	index_the_stack((&data)->a);
	
	sort_the_stack(&data);
		
	printf("\n---------->AFTER<---------- \n\n");
	print_ab(&data);
	ft_free_everything(&data);
}
