/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:02:57 by arabiai           #+#    #+#             */
/*   Updated: 2023/03/03 18:12:44 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
void	 leaks (void)
{
	system("leaks checker");
}

void apply_the_moves(t_infos *data)
{
	char 	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (ft_strncmp(line, "sa\n", 3) == 0)
			sa(data, 0);
		else if (!ft_strncmp(line, "sb\n", 3))
			sb(data, 0);
		else if (!ft_strncmp(line, "ss\n", 3))
			ssc(data);
		else if (!ft_strncmp(line, "pa\n", 3))
			pac(data);
		else if (!ft_strncmp(line, "pb\n", 3))
			pbc(data);
		else if (!ft_strncmp(line, "ra\n", 3))
			ra(data, 0);
		else if (!ft_strncmp(line, "rb\n", 3))
			rb(data, 0);
		else if (!ft_strncmp(line, "rr\n", 3))
			rrc(data);
		else if (!ft_strncmp(line, "rra\n", 4))
			rra(data, 0);
		else if (!ft_strncmp(line, "rrb\n", 4))
			rrb(data, 0);
		else if (!ft_strncmp(line, "rrr\n", 4))
			rrrc(data);
		else
		{
			free(line);
			ft_free_everything(data);
			error_and_exit("Error");
		}
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
}

int	main(int argc, char **argv)
{
	t_infos	data;

	initialize_data(&data);
	parse_arguments(argc, argv, &data);
	fill_a(&data);
	index_the_stack((&data)->a);
	apply_the_moves(&data);
	if(is_sorted((&data)->a))
	{
		ft_free_everything(&data);
		error_and_exit("OK");
	}
	else
	{
		ft_free_everything(&data);
		error_and_exit("KO");
	}
	return (0);
}