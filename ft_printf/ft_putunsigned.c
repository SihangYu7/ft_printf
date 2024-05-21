/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyu <siyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:56:50 by siyu              #+#    #+#             */
/*   Updated: 2024/05/21 15:51:19 by siyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_miniputnbr(unsigned int n, int i)
{
	if (n >= 10)
	{
		i = ft_miniputnbr(n / 10, i);
		if (i == -1)
			return (-1);
	}
	if (ft_putchar(n % 10 + '0') != 1)
		return (-1);
	i++;
	return (i);
}

int	ft_putunsigned(unsigned int n)
{
	int		len;

	len = 0;
	return (ft_miniputnbr(n, len));
}
