/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:48:30 by fsantill          #+#    #+#             */
/*   Updated: 2023/09/29 16:18:59 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
		return (1);
	return (0);
}
/**
 * The function `ft_isalpha` checks if a given character
 * is an alphabetic character.
 * 
 * @param c The parameter "c" is of type "int" and represents a character.
 * 
 * @return 1 if the character is an alphabetic character
 * (either lowercase or uppercase), and 0 otherwise.
 */