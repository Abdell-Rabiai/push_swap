/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:37:01 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/09 20:31:31 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_argv(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        while (str[i] == ' ')
            i++;
        if ((str[i] == '+' || str[i] == '-') && i == 0)
            i++;
        if ((str[i] > '9' || str[i] < '0') && str[i])
            return (0);
        i++;
    }
    return (1);
}

void push_argvi_to_a(char *str, t_infos *data)
{
    char **numbers;
    int i;
    long double my_number;

    i = 0;
    my_number = 0;
    numbers = ft_split(str, ' ');
    
    while (*numbers)
    {
        my_number = ft_atoi(*numbers);
        if (my_number >= -2147483648 && my_number <= 2147483647)
            push_to_a(my_number, data);
        else
        {
            ft_printf("ERROR : not an integer value\n");
            exit(EXIT_FAILURE);
        }
        numbers++;
    }
}