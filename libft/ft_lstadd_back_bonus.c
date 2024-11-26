/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:21:08 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/12 16:26:11 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (!lst)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	aux = *lst;
	while (aux->next != NULL)
		aux = aux->next;
	aux->next = new;
}
/**
 * The function `ft_lstadd_back` adds a new element to the end of a linked
 * list.
 * 
 * @param lst A pointer to a pointer to the first element of a linked list
 * (t_list).
 * @param new The "new" parameter is a pointer to a t_list structure that we
 * want to add to the end of the linked list.
 * 
 * @return The function does not explicitly return a value. However, if the
 * condition `if (!lst)` is true, the function will return without making
 * any changes.
 */