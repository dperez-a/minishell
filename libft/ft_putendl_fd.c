/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:02:02 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/11 16:42:05 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd (s, fd);
	write (fd, "\n", 1);
}
/**
 * The function `ft_putendl_fd` writes a string followed by a newline character
 * to a file descriptor.
 * 
 * @param s A pointer to a string that needs to be written to the file
 * descriptor.
 * @param fd The parameter "fd" is an integer representing the file descriptor
 * of the file where the string "s" will be written.
 */