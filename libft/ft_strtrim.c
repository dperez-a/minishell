/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:00:29 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/06 17:08:16 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, start, end - start));
}
/**
 * The function `ft_strtrim` trims the characters specified in the `set`
 * parameter from the beginning and end of the string `s1`.
 * 
 * @param s1 The parameter `s1` is a pointer to a constant character
 * string that we want to trim.
 * @param set The "set" parameter is a string that contains a set of characters
 * that we want to remove from the beginning and end of the "s1" string.
 * 
 * @return a trimmed version of the input string `s1`.
 */