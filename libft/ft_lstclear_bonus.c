/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:48:30 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/12 16:27:52 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*next;

	if (!lst || !del)
		return ;
	aux = *lst;
	while (aux != NULL)
	{
		next = aux->next;
		del(aux->content);
		free(aux);
		aux = next;
	}
	*lst = NULL;
}
/**
 * The function `ft_lstclear` clears a linked list by deleting each node and
 * freeing the memory.
 * 
 * @param lst A pointer to a pointer to the first node of a linked list. This
 * allows us to modify the pointer to the list if necessary.
 * @param del The "del" parameter is a function pointer that points to a
 * function responsible for deleting the content of each node in the linked
 * list. The function takes a void pointer as its parameter, which represents
 * the content of the node.
 * 
 * @return The function does not return anything. It has a void return type.
 */