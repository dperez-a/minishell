/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:07:10 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/02 17:06:17 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
/**
 * The function ft_strlen calculates the length of a string by counting
 * the number of characters until it reaches the null terminator.
 * 
 * @param str A pointer to a character array (string)
 * 
 * @return the length of the string.
 */