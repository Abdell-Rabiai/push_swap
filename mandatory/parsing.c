/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:37:01 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/20 18:46:52 by arabiai          ###   ########.fr       */
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

int	check_duplicates(char **strs)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (strs[i])
	{
		temp = strs[i];
		j = i + 1;
		while (strs[j])
		{
			if (ft_strncmp(temp, strs[j], ft_strlen(temp)) == 0
				&& ft_strncmp(temp, strs[j], ft_strlen(strs[j])) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	parse_arguments(int argc, char **argv)
{
	int		i;
	char	**splitd_arguments;
	char	*joined_arguments;

	i = 1;
	if (argc < 2)
		error_and_exit("ERROR : Not Enough Arguments !!");
	joined_arguments = join_arguments(argc, argv);
	splitd_arguments = ft_split(joined_arguments, ' ');
	if (check_duplicates(splitd_arguments))
		error_and_exit("ERROR : There Are Duplicate Arguments !!");
	else
		ft_printf("EVERYTHING IS GOOD !!\n");
	ft_printf("{%s}\n", joined_arguments);
}
