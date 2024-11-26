/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:23:23 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/20 15:56:59 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	unsigned char	*destiny;
	unsigned char	*source;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	destiny = (unsigned char *)dest;
	source = (unsigned char *)src;
	i = 0;
	while (i < count)
	{
		destiny[i] = source[i];
		i++;
	}
	return (destiny);
}
/**
 * The function `ft_memcpy` copies `count` bytes from the memory location
 * pointed to by `src` to the memory location pointed to by `dest`.
 * 
 * @param dest The `dest` parameter is a pointer to the destination
 * memory where the copied data will be stored.
 * @param src The `src` parameter is a pointer to the source memory
 * location from where the data will be copied.
 * @param count The parameter "count" represents the number of bytes
 * to be copied from the source to the destination.
 * 
 * @return a pointer to the destination memory block.
 */