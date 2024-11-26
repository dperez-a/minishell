/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:24:23 by fsantill          #+#    #+#             */
/*   Updated: 2023/09/29 16:26:59 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c <= 'z' && c >= 'a')
		c -= 32;
	return (c);
}
/**
 * The function `ft_toupper` converts a lowercase letter to uppercase.
 * 
 * @param c The parameter "c" is of type int and represents a character.
 * 
 * @return the uppercase version of the input character.
 */