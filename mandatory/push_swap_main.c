/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:17:17 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/09 20:19:35 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_printf_stack(t_stack **stack_a)
// {
// 	printf("%d ", stack_a-);
// }

t_stack* new_stack() // constructs a new stack
{
	t_stack* s = (t_stack*)malloc(sizeof(t_stack));
	s->stack_size = 0;
	s->top = NULL;
	s->bottom = NULL;
	return s;
}

int is_empty(t_infos *infos)
{
	if(infos->a->top == NULL)
		return 1;
	else
		return 0;
}

int get_top(t_infos *infos){
	return infos->a->top->number;
}

void push_to_a(int x, t_infos *infos)
{
	t_list *temp = (t_list *)malloc(sizeof(t_list));
	if(is_empty(infos) == 1)
	{
		temp->number = x;
		temp->next = NULL;
		temp->previous = NULL;
		infos->a->top = temp;
		infos->a->stack_size++;
	}
	else
	{
		temp->number = x;
		temp->next = infos->a->top;
		temp->previous = NULL;
		infos->a->top->previous = temp;
		
		infos->a->top = temp;
		infos->a->stack_size++;
	}
}

void pop_from_a(t_infos *infos)
{
	t_list *temp;
	if(infos->a->top == NULL) return;
	temp = infos->a->top;
	infos->a->top = infos->a->top->next;
	free(temp);
}

void print_stack(t_infos *infos)
{
	t_list *temp = infos->a->top;
	if(is_empty(infos) == 1)
	{
		printf("Stack is Empty\n");
		return;
	}

	printf("Top >> \n");
	while(temp != NULL)
	{
		printf("%d\n",temp->number);
		temp = temp->next;
	}
	printf("<< End\n\n");
}

int main(int argc, char **argv)
{
	int i;
	t_infos *data;

	data = (t_infos*)malloc(sizeof(t_infos));
	data->a = new_stack();
	i = 1;
	if (argc <= 1)
		ft_printf("ERROR :\t Not enough arguments\n");
	while (i <= argc - 1)
	{
		if(check_argv(argv[i]))
		{
			ft_printf("everything is good in %s\n", argv[i]);
			push_argvi_to_a(argv[i], data);
		}
		else
		{
			ft_printf("ERROR : in %s\n", argv[i]);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	print_stack(data);
	return (0);
}

	// str = NULL;
	// while (++i)
	// {
	// 	ft_strjoin(str, argv[i]);
	// 	ft_strjoin(str, " ");
	// }
	// checker_error(str);
	// f_str = ft_split(str. ' ');
	// while (f_str[++i])
	// 	ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(f_str[i])));
	// checker_error(str);
	// ft_free_split(f_str);
	