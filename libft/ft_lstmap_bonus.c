/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:21:08 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/12 16:40:37 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*aux;
	t_list	*newlst;
	t_list	*newnode;

	if (!lst || !f || !del)
		return (NULL);
	newlst = NULL;
	while (lst != NULL)
	{
		aux = f(lst->content);
		newnode = ft_lstnew(aux);
		if (!newnode || !aux)
		{
			del(aux);
			ft_lstclear(&newlst, (*del));
			ft_lstclear(&newnode, (*del));
			return (NULL);
		}
		ft_lstadd_back(&newlst, newnode);
		lst = lst->next;
	}
	return (newlst);
}
/**
 * The ft_lstmap function takes a linked list, applies a function to each
 * element, and returns a new linked list with the modified elements.
 * 
 * @param lst A pointer to the first node of a linked list.
 * @param f A function pointer that takes a void pointer as input and returns
 * a void pointer. This function is applied to each element of the input list
 * to create a new element for the output list.
 * @param del A function pointer that takes a void pointer as an argument and
 * does not return anything. This function is responsible for deleting/freeing
 * the content of a node in the linked list.
 * 
 * @return a pointer to a new linked list (`newlst`).
 */