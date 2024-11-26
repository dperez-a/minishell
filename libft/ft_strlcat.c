/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:07:13 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/12 14:23:42 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_length;
	size_t	src_length;
	size_t	ori_dest_length;

	ori_dest_length = ft_strlen((const char *) dest);
	dest_length = ori_dest_length;
	src_length = ft_strlen((const char *) src);
	i = 0;
	if (size == 0)
		return (src_length);
	if (dest_length > size)
		return (src_length + size);
	while (src[i] != '\0' && dest_length < (size - 1))
	{
		dest[dest_length] = src[i];
		i++;
		dest_length++;
	}
	dest[dest_length] = 0;
	return (src_length + ori_dest_length);
}
/**
 * The ft_strlcat function concatenates two strings, ensuring that the
 * resulting string does not exceed a specified size.
 * 
 * @param str The parameter `str` is not used in the code provided.
 * 
 * @return The function `ft_strlcat` returns the total length of the
 * concatenated string, which is the sum of the original length of the
 * destination string (`ori_dest_length`) and the length of the source
 * string (`src_length`).
 */