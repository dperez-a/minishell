/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:00:11 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/05 16:18:32 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*strnew;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	strnew = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!strnew)
		return (NULL);
	ft_memcpy(strnew, s1, len1);
	ft_memcpy(strnew + len1, s2, len2);
	strnew [len1 + len2] = '\0';
	return (strnew);
}
/**
 * The function `ft_strjoin` concatenates two strings `s1` and `s2` and
 * returns a new string.
 * 
 * @param s1 A pointer to a constant character string (string 1)
 * @param s2 The parameter `s2` is a pointer to a constant character string.
 * 
 * @return The function `ft_strjoin` returns a pointer to a newly allocated
 * string that is the concatenation of `s1` and `s2`.
 */