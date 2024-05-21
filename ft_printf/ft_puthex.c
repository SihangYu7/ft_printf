/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyu <siyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:56:23 by siyu              #+#    #+#             */
/*   Updated: 2024/05/21 15:40:27 by siyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n, char format)
{
	char			*hex_digits;
	unsigned int	num;
	int				rslt;
	int				temp;

	if (format == 'x')
		hex_digits = "0123456789abcdef";
	else
		hex_digits = "0123456789ABCDEF";
	rslt = 0;
	temp = 0;
	num = (unsigned int)n;
	if (num >= 16)
	{
		temp = ft_puthex(num / 16, format);
		if (temp == -1)
			return (-1);
		rslt += temp;
	}
	temp = ft_putchar(*(hex_digits + (num % 16)));
	if (temp == -1)
		return (-1);
	rslt += temp;
	return (rslt);
}
