/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyu <siyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:43:14 by siyu              #+#    #+#             */
/*   Updated: 2024/05/21 15:30:31 by siyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putadrs(void *format);
int	ft_puthex(unsigned long n, char format);
int	ft_putunsigned(unsigned int n);
int	ft_putchar(char c);
int	ft_putstr(char const *str);
int	ft_putnbr(int n);
int	ft_printf(const char *str, ...);

#endif
