/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:32:18 by arabiai           #+#    #+#             */
/*   Updated: 2023/03/01 17:12:48 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_and_exit(char *error)
{
	ft_printf("%s\n", error);
	exit(EXIT_FAILURE);
}

int	is_all_spaces(char *arg)
{
	while (*arg)
	{
		if (*arg != ' ')
			return (0);
		arg++;
	}
	return (1);
}

int	is_there_character(char *arg)
{
	while (*arg)
	{
		if ((*arg > '9' || *arg < '0') && *arg != ' '
			&& (*arg != '+' && *arg != '-'))
			return (1);
		else if ((*arg == '+' || *arg == '-')
			&& (*(arg + 1) == '+' || *(arg + 1) == '-'))
			error_and_exit("ERROR");
		arg++;
	}
	return (0);
}

int	is_there_character_after_the_number(char *arg)
{
	while (*arg == ' ')
		arg++;
	if (*arg == '-' || *arg == '+')
		arg++;
	while ((*arg >= '0' && *arg <= '9'))
		arg++;
	if ((*arg > '9' || *arg < '0') && *arg != '\0' && *arg != ' ')
		return (1);
	else
		return (0);
}

void	check_argument(char *arg)
{
	if (*arg == '\0')
		error_and_exit("ERROR");
	else if (is_all_spaces(arg))
		error_and_exit("ERROR");
	else if (is_there_character(arg))
		error_and_exit("ERROR");
	else if (is_there_character_after_the_number(arg))
		error_and_exit("ERROR");
}
