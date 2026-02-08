/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:25:07 by daogawa           #+#    #+#             */
/*   Updated: 2025/11/02 18:08:06 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_big_rec(unsigned int n)
{
	char	*hex_code;
	int		ret;
	int		cnt;

	hex_code = "0123456789ABCDEF";
	cnt = 0;
	if (n >= 16)
	{
		ret = ft_puthex_big_rec(n / 16);
		if (ret == -1)
			return (-1);
		cnt += ret;
	}
	if (write(1, &hex_code[n % 16], 1) != 1)
		return (-1);
	cnt++;
	return (cnt);
}

int	ft_puthex_big(unsigned int n)
{
	return (ft_puthex_big_rec(n));
}
