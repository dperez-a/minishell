/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:07:18 by fsantill          #+#    #+#             */
/*   Updated: 2023/09/29 16:19:55 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}
/**
 * The function `ft_isdigit` checks if a given character is a digit.
 * 
 * @param c The parameter "c" is of type "int" and represents a character.
 * 
 * @return 1 if the character is a digit (0-9), and 0 otherwise.
 */