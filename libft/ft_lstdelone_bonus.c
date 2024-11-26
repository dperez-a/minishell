/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:21:08 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/12 16:26:36 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/**
 * The function `ft_lstdelone` deletes a single node from a linked list
 * and frees the memory associated with it.
 * 
 * @param lst A pointer to the element in the linked list that needs to
 * be deleted.
 * @param del The "del" parameter is a function pointer that points to a
 * function responsible for deleting the content of a node in a linked list.
 * The function takes a void pointer as its parameter, which represents
 * the content of the node to be deleted.
 * 
 * @return nothing (void).
 */