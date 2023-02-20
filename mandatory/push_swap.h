/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:53:05 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/20 18:31:41 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "../libft_utils/libft_utils.h"

typedef struct s_infos
{
	int			stack_size;
	t_stack		*a;
	t_stack		*b;
}	t_infos;

/*PARSING*/
void		parse_arguments(int argc, char **argv);
void		error_and_exit(char *error);
int			is_all_spaces(char *arg);
int			is_there_character(char *arg);
int			is_there_character_after_the_number(char *arg);
void		check_argument(char *arg);

#endif