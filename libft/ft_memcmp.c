/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:26:45 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/02 14:15:04 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buffer1, const void *buffer2, size_t count)
{
	unsigned char			mem1;
	unsigned char			mem2;
	const unsigned char		*ptr1;
	const unsigned char		*ptr2;

	ptr1 = (const unsigned char *)buffer1;
	ptr2 = (const unsigned char *)buffer2;
	while (count > 0)
	{
		mem1 = *ptr1;
		mem2 = *ptr2;
		if (mem1 < mem2)
			return (mem1 - mem2);
		else if (mem1 > mem2)
			return (mem1 - mem2);
		ptr1++;
		ptr2++;
		count--;
	}
	return (0);
}

/**
 * The function `ft_memcmp` compares two memory buffers and returns an
 * integer indicating their relative order.
 * 
 * @param buffer1 A pointer to the first buffer of memory to be compared.
 * @param buffer2 The `buffer2` parameter is a pointer to the second buffer
 * that you want to compare.
 * It is of type `const void *`, which means it can be a pointer to any
 * type of data.
 * @param count The parameter "count" represents the number of bytes to
 * compare between the two buffers.
 * 
 * @return an integer value. If the contents of buffer1 are less than the
 * contents of buffer2, it returns -1. If the contents of buffer1 are greater
 * than the contents of buffer2, it returns 1. If the contents of buffer1 are
 * equal to the contents of buffer2, it returns 0.
 */