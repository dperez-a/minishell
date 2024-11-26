/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:21:30 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/12 16:27:41 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*aux;

	if (!lst || !f)
		return ;
	aux = lst;
	while (aux != NULL)
	{
		f(aux->content);
		aux = aux->next;
	}
}
/**
 * The function `ft_lstiter` iterates through a linked list and applies a
 * given function to each element.
 * 
 * @param lst A pointer to the first node of a linked list.
 * @param f The parameter `f` is a function pointer that points to a function
 * that takes a `void*`
 * parameter and returns `void`. This function will be applied to each element
 * of the linked list `lst`.
 * 
 * @return In the given code, the function `ft_lstiter` does not explicitly
 * return any value. It has a return type of `void`, which means it does not
 * return anything.
 */