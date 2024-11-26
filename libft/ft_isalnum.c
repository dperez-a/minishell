/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:21:30 by fsantill          #+#    #+#             */
/*   Updated: 2023/09/29 16:18:24 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A')
		|| (c <= '9' && c >= '0'))
		return (1);
	return (0);
}
/**
 * The function `ft_isalnum` checks if a given character is alphanumeric.
 * 
 * @param c The parameter "c" is of type "int" and represents a character.
 * 
 * @return 1 if the character is alphanumeric
 * (a letter or a digit), and 0 otherwise.
 */