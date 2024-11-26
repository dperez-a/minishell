/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:26:14 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/12 14:26:19 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *buffer, int c, size_t count)
{
	while (count > 0)
	{
		if (*(unsigned char *)buffer == (unsigned char) c)
		{
			if ((unsigned char)c == '\0')
				return (buffer);
			else
				return (buffer);
		}
		buffer = (unsigned char *)buffer + 1;
		count--;
	}
	return (NULL);
}

/**
 * The function ft_memchr searches for a specific character in a given buffer
 * and returns a pointer to the first occurrence of that character,
 * or NULL if it is not found.
 * 
 * @param buffer A pointer to the memory area to be searched.
 * @param c The parameter "c" is the character that we are searching for in
 * the buffer. It is of type "int" because it can represent any character
 * value, including special characters.
 * @param count The parameter "count" represents the number of bytes to be
 * searched in the buffer.
 * 
 * @return a pointer to the first occurrence of the character 'c' in the
 * given buffer. If the character is not found, it returns NULL.
 */