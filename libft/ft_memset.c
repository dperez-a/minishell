/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:37:27 by fsantill          #+#    #+#             */
/*   Updated: 2023/09/29 16:23:18 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t count)
{
	unsigned char	*destiny;
	size_t			i;

	destiny = dest;
	i = 0;
	while (i < count)
	{
		destiny[i] = (unsigned char)c;
		i++;
	}
	return (destiny);
}
/**
 * The function ft_memset sets a specified number of bytes in a memory
 * block to a specified value.
 * 
 * @param dest The `dest` parameter is a pointer to the memory block that you
 * want to fill with a specific value.
 * @param c The parameter "c" is an integer that represents the value to be
 * set in each byte of the memory block pointed to by "dest".
 * @param count The parameter "count" represents the number of bytes to be
 * set in the memory block pointed to by "dest".
 * 
 * @return a pointer to the destination memory block.
 */