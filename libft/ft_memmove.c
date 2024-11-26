/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:36:25 by fsantill          #+#    #+#             */
/*   Updated: 2023/09/29 16:21:55 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	void	*destiny;

	destiny = dest;
	if (dest == 0 && src == 0)
		return (destiny);
	if (dest == src)
		return (destiny);
	if (dest > src)
		while (count--)
			((unsigned char *)dest)[count] = ((unsigned char *)src)[count];
	else
		while (count--)
			*(unsigned char *)dest++ = *(unsigned char *)src++;
	return (destiny);
}
/**
 * The function `ft_memmove` copies a specified number of bytes from the
 * source memory location to the destination memory location,
 * handling overlapping memory regions correctly.
 * 
 * @param dest The `dest` parameter is a pointer to the destination memory
 * where the copied data will be stored.
 * @param src The `src` parameter is a pointer to the source memory
 * location from where the data will be copied.
 * @param count The parameter "count" represents the number of bytes
 * to be copied from the source memory location to the destination
 * memory location.
 * 
 * @return a pointer to the destination memory block.
 */