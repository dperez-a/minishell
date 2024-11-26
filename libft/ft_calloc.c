/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:40:05 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/04 17:27:31 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*assignmem;

	if (number == 0 || size == 0)
		return (malloc (0));
	if (!(number < SIZE_MAX / size))
		return (NULL);
	assignmem = (void *)malloc(number * size);
	if (assignmem == 0)
		return (NULL);
	ft_bzero(assignmem, number * size);
	return (assignmem);
}

/** I need a true condition in: (number < SIZE_MAX / size).
 * That condition is like: (number * size < SIZE_MAX).
 * Other way is (size_t - 1) that is almost the longest
 * number of a size_t (unsigned long).
 * So I am trying to avoid an overflow when I multiply number & size.
 */

/**
 * The ft_calloc function allocates memory for an array of elements
 * and initializes the memory to zero.
 * 
 * @param number The number of elements to allocate memory for.
 * @param size The size parameter represents the size in bytes of each
 * element in the allocated memory block.
 * 
 * @return a pointer to the allocated memory.
 */