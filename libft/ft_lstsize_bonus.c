/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:07:18 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/12 16:27:02 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/**
 * The function `ft_lstsize` calculates the size of a linked list.
 * 
 * @param lst The parameter "lst" is a pointer to a linked list of
 * type "t_list".
 * 
 * @return the size of the linked list.
 */