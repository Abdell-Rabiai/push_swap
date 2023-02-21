/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:37:01 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/21 16:07:48 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_arguments(int argc, char **argv)
{
	int		i;
	char	*arg;
	char	*temp;

	i = 1;
	arg = "";
	while (i < argc)
	{
		check_argument(argv[i]);
		temp = ft_strjoin(argv[i], " ");
		arg = ft_strjoin(arg, temp);
		i++;
	}
	return (arg);
}

void	fill_numbers(char **strs, t_infos *data)
{
	int		i;
	long	atoi;

	i = 0;
	while (i < data->stack_size && strs[i])
	{
		atoi = ft_atoi(strs[i]);
		if (atoi == UINT_MAX)
			error_and_exit("ERROR : Argument Is Not An Integer");
		data->numbers[i] = atoi;
		i++;
	}
}

int	check_duplicates(char **strs, t_infos *data)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	j = 0;
	data->numbers = (int *)malloc(data->stack_size * sizeof(int));
	fill_numbers(strs, data);
	while (i < data->stack_size)
	{
		temp = data->numbers[i];
		j = i + 1;
		while (j < data->stack_size)
		{
			if (temp == data->numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	parse_arguments(int argc, char **argv, t_infos *data)
{
	char	**splitd_arguments;
	char	*joined_arguments;

	if (argc < 2)
		error_and_exit("ERROR : Not Enough Arguments !!");
	joined_arguments = join_arguments(argc, argv);
	data->stack_size = ft_how_many_words(joined_arguments, ' ');
	splitd_arguments = ft_split(joined_arguments, ' ');
	if (check_duplicates(splitd_arguments, data))
		error_and_exit("ERROR : There Are Duplicate Arguments !!");
	else
		ft_printf("EVERYTHING IS GOOD !!\n\n");
	ft_printf("The Args joined : {%s}\n\n", joined_arguments);
}
