/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:01:08 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/11 15:23:05 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*end;
	size_t			length;
	unsigned int	i;

	i = 0;
	length = ft_strlen(s);
	if (!s || !f)
		return (NULL);
	end = (char *)malloc((length + 1) * sizeof(char));
	if (!end)
		return (NULL);
	while (s[i] != '\0')
	{
		end[i] = f(i, s[i]);
		i++;
	}
	end[i] = '\0';
	return (end);
}
/**
 * The function `ft_strmapi` takes a string `s` and a function `f` as
 * parameters, and applies the function `f` to each character of the string
 * `s` to create a new string.
 * 
 * @param s A pointer to a constant character string. This is the input string
 * that we want to apply the function `f` to.
 * @param f The parameter `f` is a function pointer that takes two arguments:
 * an unsigned integer `i` and a character `c`. The function `f` is expected to
 * perform some operation on the character `c` and return a modified character.
 * 
 * @return a pointer to a character, which represents the modified string after
 * applying the function f to each character in the input string s.
 */