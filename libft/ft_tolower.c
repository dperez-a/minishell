/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:24:43 by fsantill          #+#    #+#             */
/*   Updated: 2023/09/29 16:26:44 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c <= 'Z' && c >= 'A')
		c += 32;
	return (c);
}
/**
 * The function `ft_tolower` converts an uppercase letter to lowercase.
 * 
 * @param c The parameter "c" is of type int and represents a character.
 * 
 * @return the lowercase equivalent of the input character.
 */