/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:34:29 by daogawa           #+#    #+#             */
/*   Updated: 2025/11/05 21:08:57 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(const char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_puthex(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (ft_puthex_big(va_arg(args, unsigned int)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	err_handle(va_list args, int status)
{
	if (status == -1)
	{
		va_end(args);
		return (-1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		status;

	va_start(args, format);
	len = 0;
	while (*format)
	{
		status = 0;
		if (*format == '%')
			status = (int)print_format(*(++format), args);
		else
		{
			write(1, format, 1);
			len++;
		}
		if (err_handle(args, status) == -1)
			return (-1);
		len += status;
		format++;
	}
	va_end(args);
	return (len);
}
