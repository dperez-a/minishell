/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:27:09 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/03 11:16:40 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t slen)
{
	size_t	find_len;

	find_len = ft_strlen(find);
	if (find_len == 0)
		return ((char *)str);
	while (*str && slen >= find_len)
	{
		if (ft_strncmp(str, find, find_len) == 0)
			return ((char *)str);
		str++;
		slen--;
	}
	return (NULL);
}

/**
 * The function `ft_strnstr` searches for the first occurrence of a substring
 * within a given string, up to a specified length.
 * 
 * @param str A pointer to the string in which to search for the substring.
 * @param find The "find" parameter is a pointer to the substring that we are
 * searching for within the "str" string.
 * @param slen The parameter "slen" represents the maximum number of characters
 * to search in the string "str".
 * 
 * @return a pointer to the first occurrence of the string "find" within the
 * string "str" up to a maximum length of "slen". If the "find" string is
 * empty, it will return a pointer to the "str" string. If no occurrence is
 * found, it will return NULL.
 */