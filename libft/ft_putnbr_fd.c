/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:02:15 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/11 17:02:34 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long	nb_aux;
	char	digit;

	nb_aux = nb;
	if (nb_aux < 0)
	{
		write(fd, "-", 1);
		nb_aux = -nb_aux;
	}
	if (nb_aux < 10)
	{
		digit = nb_aux + 48;
		write(fd, &digit, 1);
	}
	if (nb_aux >= 10)
	{
		ft_putnbr_fd(nb_aux / 10, fd);
		digit = nb_aux % 10 + 48;
		write(fd, &digit, 1);
	}
}
/**
 * @param nb_aux The parameter "nb_aux" is a long to manage the minimum value
 * of an integer (-2147483648).
 */

/**
 * The function `ft_putnbr_fd` takes an integer and a file descriptor as input
 * and writes the integer to the specified file descriptor.
 * 
 * @param nb The number to be printed.
 * @param fd The parameter "fd" represents the file descriptor of the file
 * where the output will be written.
 */