/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:21:30 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/12 16:26:57 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(1 * sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/**
 * The function ft_lstnew creates a new node for a linked list with the
 * given content.
 * 
 * @param content The "content" parameter is a void pointer that represents
 * the data that will be stored in the new node of the linked list.
 * It can be any type of data, as it is a generic pointer.
 * 
 * @return a pointer to a newly created t_list node.
 */