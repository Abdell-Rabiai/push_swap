/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:53:05 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/28 18:48:21 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "../libft_utils/libft_utils.h"

typedef struct s_node
{
	int				number;
	int				index;
	int				indice;
	int				moves;
	struct s_node	*next;
	struct s_node	*previous;
}					t_node;
typedef struct s_deque
{
	int				size;
	int				min;
	int				max;
	struct s_node	*head;
	struct s_node	*tail;
}	t_deque;

typedef struct s_infos
{
	int			stack_size;
	int			*numbers;
	t_deque		*a;
	t_deque		*b;
}	t_infos;

/*PARSING*/
void		parse_arguments(int argc, char **argv, t_infos *data);
void		error_and_exit(char *error);
int			is_all_spaces(char *arg);
int			is_there_character(char *arg);
int			is_there_character_after_the_number(char *arg);
void		check_argument(char *arg);
int			ft_get_size(t_deque *deck);
/*Deque_Operations*/

// t_node		*ft_new_node(int number);
t_node		*ft_new_node(int number, int index, int indice);
void		ft_push_rear(t_deque *deck, t_node *poped);
void		ft_push_front(t_deque *deck, t_node *poped);
t_node		*ft_pop_front(t_deque *deck);
t_node		*ft_pop_rear(t_deque *deck);
void		ft_free_everything(t_infos *data);
void		ft_free_stack(t_deque *a);
t_node		*get_max_node(t_deque *a);
/*Push Swao Moves*/

void		sa(t_infos *data, bool print);
void		sb(t_infos *data, bool print);
void		ss(t_infos *data);
void		pa(t_infos *data);
void		pb(t_infos *data);
void		ra(t_infos *data, bool print);
void		rb(t_infos *data, bool print);
void		rr(t_infos *data);
void		rra(t_infos *data, bool print);
void		rrb(t_infos *data, bool print);
void		rrr(t_infos *data);
/**Algorithms helpers*/

void		sort_the_stack(t_infos *data);
void		sort_3(t_infos *data);
int			return_max(t_deque *a);
int			return_before_max(t_deque *a);
int			return_min(t_deque *a);
int			return_min_for_indexing(t_deque *a);
void		index_the_stack(t_deque *a);
bool		is_sorted(t_deque *a);
int			get_number_of_instructions(t_deque *a, t_node *temp_b);
t_node		*get_before_max_node(t_deque *a);
int			return_position(t_deque *a, t_node *temp_b);
void		print_ab(t_infos *data);
t_node		*return_lowest(t_deque *a, int start_of_chunk, int end_of_chunk);

void		sort_2(t_infos *data);

void		push_chunks_back_to_a(t_infos *data);
void		push_chunks_to_b(t_infos *data);

#endif