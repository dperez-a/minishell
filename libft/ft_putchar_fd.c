/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:01:33 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/11 16:29:19 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/**
 * The function ft_putchar_fd writes a single character to a specified file
 * descriptor.
 * 
 * @param c The character to be written to the file descriptor.
 * @param fd The parameter "fd" is an integer representing the file descriptor.
 * It is used to specify the file or stream to which the character "c" will
 * be written.
 */