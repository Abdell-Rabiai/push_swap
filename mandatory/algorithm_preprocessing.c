/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_preprocessing.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:16:32 by arabiai           #+#    #+#             */
/*   Updated: 2023/03/01 13:51:32 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_number_of_instructions(t_deque *a, t_node *temp_b)
{
	int	i;
	int	position;

	i = 0;
	position = return_position(a, temp_b);
	if (position > ft_get_size(a) / 2 && position)
		i = ft_get_size(a) - position;
	if (position <= ft_get_size(a) / 2 && position)
		i = position;
	if (position == 0)
		i = 0;
	return (i);
}

int	return_position(t_deque *a, t_node *temp_b)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = a->head;
	while (temp && temp_b)
	{
		if (temp->number == temp_b->number)
			return (i);
		i++;
		temp = temp->next;
	}
	return (0);
}

void	indice_the_stack(t_deque *a)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = a->head;
	while (temp)
	{
		temp->indice = i;
		i++;
		temp = temp->next;
	}
}

void	index_the_stack(t_deque *a)
{
	t_node	*temp_a;
	t_node	*temp_b;
	int		i;

	temp_a = a->head;
	i = 0;
	while (temp_a)
	{
		temp_b = a->head;
		while (temp_b)
		{
			if (temp_a->number > temp_b->number)
				i++;
			temp_b = temp_b->next;
		}
		temp_a->index = i;
		i = 0;
		temp_a = temp_a->next;
	}
	indice_the_stack(a);
}
