/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:00:56 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/10 16:31:17 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countdigits(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*stritoa;
	int		digits;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	digits = countdigits(n);
	stritoa = (char *)malloc((digits + 1) * sizeof(char));
	if (!stritoa)
		return (NULL);
	if (n == 0)
		stritoa[0] = '0';
	if (n < 0)
	{
		stritoa[0] = '-';
		n *= -1;
	}
	stritoa[digits] = '\0';
	digits--;
	while (digits >= 0 && n != 0)
	{
		stritoa[digits] = (n % 10) + '0';
		digits--;
		n /= 10;
	}
	return (stritoa);
}
/**
 * The function "countdigits" calculates the number of digits in a
 * given integer.
 * 
 * @param n The parameter "n" in the countdigits function represents the
 * number for which we want to count the number of digits.
 * 
 * @return the number of digits in the given integer.
 */

/**
 * The function `ft_itoa` converts an integer into a string representation.
 * 
 * @param n The parameter `n` is an integer that represents the number to be
 * converted to a string.
 * 
 * @return a dynamically allocated string (char*) that represents the input
 * integer (n) converted to a string.
 */