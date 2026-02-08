/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:56:03 by daogawa           #+#    #+#             */
/*   Updated: 2025/11/02 18:08:52 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_rec(unsigned long n)
{
	char	*hex_code;
	int		ret;
	int		cnt;

	hex_code = "0123456789abcdef";
	cnt = 0;
	if (n >= 16)
	{
		ret = ft_putptr_rec(n / 16);
		if (ret == -1)
			return (-1);
		cnt += ret;
	}
	if (write(1, &hex_code[n % 16], 1) != 1)
		return (-1);
	cnt++;
	return (cnt);
}

int	ft_putptr(void *ptr)
{
	unsigned long	address;

	address = (unsigned long)ptr;
	if (address == 0)
	{
		if (write(1, "(nil)", 5) != 5)
			return (-1);
		return (5);
	}
	if (write(1, "0x", 2) != 2)
		return (-1);
	return (2 + ft_putptr_rec(address));
}
