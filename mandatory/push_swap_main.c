/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:17:17 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/09 21:29:53 by arabiai          ###   ########.fr       */
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
	// s->stack_size = 0;
	s = NULL;
	return s;
}

int is_empty(t_infos *infos)
{
	if(infos->a == NULL)
		return 1;
	else
		return 0;
}

int get_top(t_infos *infos){
	return infos->a->number;
}

void push_to_a(int x, t_infos *infos)
{
	t_stack *temp = (t_stack *)malloc(sizeof(t_stack));
	t_stack	*tmp_a;
	if(is_empty(infos) == 1)
	{
		temp->number = x;
		temp->next = NULL;
		temp->previous = NULL;
		infos->a = temp;
		infos->stack_size++;
	}
	else
	{
		tmp_a = infos->a;
		while (tmp_a->next != NULL)
			tmp_a = tmp_a->next;
		temp->number = x;
		temp->next = NULL;
		temp->previous = tmp_a;
		tmp_a->next = temp;
		infos->stack_size++;
	}
}

void pop_from_a(t_infos *infos)
{
	t_stack *temp;
	if(infos->a == NULL) return;
	temp = infos->a;
	infos->a = infos->a->next;
	free(temp);
}

void print_stack(t_infos *infos)
{
	t_stack *temp = infos->a;
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
	