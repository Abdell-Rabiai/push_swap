/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:08:46 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/21 16:20:46 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft_utils.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	(*new_node).number = content;
	(*new_node).next = NULL;
	(*new_node).previous = NULL;
	return (new_node);
}
