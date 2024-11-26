/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:19:12 by fsantill          #+#    #+#             */
/*   Updated: 2023/09/29 16:17:54 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *dest, size_t count)
{
	unsigned char	*destiny;
	size_t			i;

	destiny = dest;
	i = 0;
	while (i < count)
	{
		destiny[i] = 0;
		i++;
	}
	return (destiny);
}
/**
 * The function `ft_bzero` sets a block of memory to zero.
 * 
 * @param dest A pointer to the memory block that needs to be zeroed out.
 * @param count The parameter "count" represents the number of bytes
 * to be set to zero in the memory
 * block pointed to by "dest".
 * 
 * @return a pointer to the destination memory block that has been zeroed out.
 */