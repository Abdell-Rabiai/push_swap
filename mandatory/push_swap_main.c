/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:48:38 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/21 13:23:53 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_data(t_infos *data)
{
	data->a = NULL;
	data->b = NULL;
	data->numbers = NULL;
	data->stack_size = 0;
}

int	main(int argc, char **argv)
{
	t_infos	data;

	initialize_data(&data);
	parse_arguments(argc, argv, &data);
}
