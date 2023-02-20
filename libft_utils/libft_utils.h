/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:05:33 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/20 18:31:24 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_UTILS_H
# define LIBFT_UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
	struct s_stack	*previous;
}					t_stack;

size_t		ft_strlen(const char *str);
long double	ft_atoi(const char *str);
int			ft_atohex(const char *str);
int			get_index_base(int c, int base);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		file_error(int argc, char **argv);

/*split*/
int			ft_how_many_words(const char *s, char c);
char		**ft_free_split(char **strings);
int			ft_get_length_of_word(const char *s, char c);
char		*return_the_first_word(const char *s, char c);
char		**ft_split(char const *s, char c);

/**linked lists*/

t_stack		*ft_lstnew(int number);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
int			ft_lstsize(t_stack *lst);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		ft_lstclear(t_stack **lst, void (*del)(void*));

#endif