/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:48:38 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/22 17:23:29 by arabiai          ###   ########.fr       */
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

	i = 0;
	while (i < data->stack_size)
	{
		ft_push_rear(data->a, data->numbers[i]);
		i++;
	}
}

void print_ab(t_infos *data)
{
	t_node *temp_a;
	t_node *temp_b;

	temp_a = data->a->head;
	temp_b = data->b->head;
	ft_printf("stack A <----> stack B\n");
	while (temp_a != NULL && temp_b != NULL)
	{
		ft_printf("%d              %d\n", temp_a->number, temp_b->number);
		temp_a = temp_a->next;
		temp_b = temp_b->next;
	}
	while (temp_a != NULL)
	{
		ft_printf("%d\n", temp_a->number);
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
	t_infos	*data;

	data = (t_infos *)malloc(sizeof(t_infos));
	initialize_data(data);
	parse_arguments(argc, argv, data);
	fill_a(data);

	printf("\nBEFORE \n\n");
	print_ab(data);
	
	swap(data->a, 'a', 1);

	printf("Size Before %d :\n", data->a->size);
	push_b(data);
	push_b(data);
	push_b(data);
	printf("Size after %d :\n", data->a->size);
	rotate_up(data->a, 'a', 1);
	rotate_up(data->b, 'b', 1);

	rotate_down(data->a, 'a', 1);
	rotate_down(data->b, 'b', 1);
	rotate_down_both(data);

	push_a(data);
	push_a(data);
	push_a(data);

	
	printf("\nAFTER \n\n");
	print_ab(data);
}
