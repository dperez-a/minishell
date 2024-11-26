/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:07:15 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/02 17:06:28 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while ((i < n) && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((int)(unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i != n)
		return ((int)(unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
/**
 * The function ft_strncmp compares two strings up to a specified
 * number of characters and returns the difference between
 * the first differing characters.
 * 
 * @param s1 A pointer to the first string to be compared.
 * @param s2 The parameter `s2` is a pointer to a character
 * array (string) that you want to compare with `s1`.
 * @param n The parameter `n` in the `ft_strncmp` function
 * represents the maximum number of characters to compare
 * between the two strings `s1` and `s2`.
 * 
 * @return an integer value.
 */