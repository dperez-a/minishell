/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:21:08 by fsantill          #+#    #+#             */
/*   Updated: 2023/09/29 16:19:33 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c <= 127 && c >= 0)
		return (1);
	return (0);
}
/**
 * The function `ft_isascii` checks if a given character
 * is a valid ASCII character.
 * 
 * @param c The parameter "c" is an integer representing a character.
 * 
 * @return 1 if the given character is an ASCII character
 * (with a value between 0 and 127), and 0 otherwise.
 */