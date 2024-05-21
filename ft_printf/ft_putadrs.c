/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyu <siyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:48:00 by siyu              #+#    #+#             */
/*   Updated: 2024/05/21 15:31:12 by siyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_num_in_base(unsigned long n, const char *base)
{
	int	rslt;
	int	temp;

	rslt = 0;
	if (n >= 16)
	{
		temp = print_num_in_base(n / 16, base);
		if (temp == -1)
			return (-1);
		rslt += temp;
	}
	temp = ft_putchar(*(base + (n % 16)));
	if (temp == -1)
		return (-1);
	rslt += temp;
	return (rslt);
}

int	ft_putadrs(void *format)
{
	unsigned long	addr;
	const char		*hex_digits;
	int				rslt;
	int				temp;

	addr = (unsigned long)format;
	hex_digits = "0123456789abcdef";
	rslt = ft_putstr("0x");
	if (rslt == -1)
		return (-1);
	temp = print_num_in_base(addr, hex_digits);
	if (temp == -1)
		return (-1);
	rslt += temp;
	return (rslt);
}
