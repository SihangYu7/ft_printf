/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyu <siyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:43:25 by siyu              #+#    #+#             */
/*   Updated: 2024/05/21 16:46:09 by siyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conversion(va_list args, char format)
{
	void	*ptr;

	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr)
			return (ft_putadrs(ptr));
		return (ft_putstr("0x0"));
	}
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), format));
	return (0);
}

static	int	protection(va_list args, char format)
{
	if (format != '%')
		return (conversion(args, format));
	else
		return (write(1, &format, 1));
}

static	int	count(const char *str, va_list args, int rslt)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!str[i + 1])
				return (0);
			temp = protection(args, str[++i]);
			if (temp == -1)
				return (-1);
			rslt += temp;
		}
		else
		{
			if (write(1, &str[i], 1) != 1)
				return (-1);
			rslt++;
		}
		i++;
	}
	return (rslt);
}

int	ft_printf(const char *str, ...)
{
	int		rslt;
	va_list	args;

	rslt = 0;
	va_start(args, str);
	rslt = count(str, args, rslt);
	va_end(args);
	return (rslt);
}
