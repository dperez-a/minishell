/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:01:22 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/11 16:24:35 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s && f)
		while (*s)
			f(i++, s++);
}
/**
 * The function `ft_striteri` iterates through a string and applies a function
 * to each character, along with its index.
 * 
 * @param s A pointer to a string (array of characters) that we want to
 * iterate over.
 * @param f The parameter "f" is a function pointer that points to a function
 * with the following signature: void (*f)(unsigned int, char*). This means
 * that "f" is a pointer to a function that takes two arguments - an
 * unsigned int and a char pointer - and returns void.
 */