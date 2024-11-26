/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:01:45 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/11 16:33:18 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	aux;

	aux = 0;
	while (str[aux] != '\0')
	{
		write(fd, &str[aux], 1);
		aux++;
	}
}
/**
 * The function `ft_putstr_fd` writes a string to a specified file descriptor.
 * 
 * @param str A pointer to a character array (string) that we want to write to
 * the file descriptor.
 * @param fd The parameter "fd" is an integer representing the file descriptor
 * of the file where the string will be written.
 */