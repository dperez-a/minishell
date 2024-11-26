/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:22:01 by fsantill          #+#    #+#             */
/*   Updated: 2023/09/29 16:20:22 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c <= 126 && c >= 32)
		return (1);
	return (0);
}
/**
 * The function `ft_isprint` checks if a given character
 * is a printable ASCII character.
 * 
 * @param c The parameter "c" is an integer representing
 * the ASCII value of a character.
 * 
 * @return 1 if the character is printable
 * (ASCII value between 32 and 126 inclusive), and 0 otherwise.
 */