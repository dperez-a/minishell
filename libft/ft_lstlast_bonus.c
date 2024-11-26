/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:07:18 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/12 16:27:32 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/**
 * The function ft_lstlast returns a pointer to the last element of a
 * linked list.
 * 
 * @param lst The parameter "lst" is a pointer to the first node of a
 * linked list.
 * 
 * @return the last node of the linked list.
 */