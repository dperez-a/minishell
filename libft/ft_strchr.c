/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:25:09 by fsantill          #+#    #+#             */
/*   Updated: 2023/09/29 16:24:01 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0' || *str == (char)c)
	{
		if (*str == (unsigned char) c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
/**
 * The function ft_strchr searches for the first occurrence of a character
 * in a string and returns a pointer to that character.
 * 
 * @param str A pointer to the string that we want to search in.
 * @param c The parameter "c" is of type "int" and represents the character
 * we are searching for in the string. It can be any valid ASCII value.
 * 
 * @return a pointer to the first occurrence of the character 'c' in the
 * string 'str'. If the character is not found, it returns NULL.
 */