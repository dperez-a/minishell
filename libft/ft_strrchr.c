/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:25:34 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/05 16:19:05 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int					i;
	const unsigned char	caux = (unsigned char)c;

	i = ft_strlen(str) - 1;
	if (caux == '\0')
		return ((char *)&str[i + 1]);
	while (i >= 0)
	{
		if (str[i] == caux)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}

/**
 * str[i] == *(str + i)
*/

/**
 * The function ft_strrchr searches for the last occurrence of a character
 * in a string and returns a pointer to that character.
 * 
 * @param str A pointer to the string in which to search for the character.
 * @param c The parameter "c" is the character that we are searching
 * for in the string.
 * 
 * @return a pointer to the last occurrence of the character 'c' in the
 * string 'str'. If 'c' is not found, it returns NULL.
 */