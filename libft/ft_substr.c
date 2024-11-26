/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:59:50 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/05 16:19:46 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	sub_i;
	char	*sub_s;

	i = start;
	sub_i = 0;
	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub_s = (char *)malloc((len + 1) * sizeof(char));
	if (!sub_s)
		return (NULL);
	while (s[i] != '\0' && sub_i < len)
	{
		sub_s[sub_i] = s[i];
		sub_i++;
		i++;
	}
	sub_s[sub_i] = '\0';
	return (sub_s);
}

/**
 * The function `ft_substr` takes a string `s`, a starting index `start`,
 * and a length `len`, and returns a substring of `s` starting from `start`
 * with a length of `len`.
 * 
 * @param s A pointer to a constant character string (input string).
 * @param start The start parameter is the index at which the substring
 * should start in the original string.
 * @param len The `len` parameter in the `ft_substr` function is the maximum
 * length of the substring that you want to extract from the input string `s`.
 * 
 * @return The function `ft_substr` returns a pointer to a newly allocated
 * substring of the input string `s`.
 */