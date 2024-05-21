/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyu <siyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:11:42 by siyu              #+#    #+#             */
/*   Updated: 2024/05/21 15:31:34 by siyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_putnbr_i(int n, int i)
{
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) != 11)
			return (-1);
		return (11);
	}
	if (n < 0)
	{
		if (write(1, "-", 1) != 1)
			return (-1);
		n = -n;
		i++;
	}
	if (n >= 10)
	{
		i = ft_putnbr_i(n / 10, i);
		if (i == -1)
			return (-1);
	}
	if (ft_putchar(n % 10 + '0') != 1)
		return (-1);
	return (++i);
}

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	return (ft_putnbr_i(n, len));
}
