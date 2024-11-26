/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:22:01 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/12 16:26:20 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (!lst || !new)
		return ;
	aux = *lst;
	*lst = new;
	new->next = aux;
}
/**
 * The function `ft_lstadd_front` adds a new element to the front of a
 * linked list.
 * 
 * @param lst A pointer to a pointer to the first node of a linked list.
 * @param new The "new" parameter is a pointer to a t_list structure that
 * represents the new node to be added to the front of the list.
 * 
 * @return The function does not explicitly return a value.
 */