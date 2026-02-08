/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:59:44 by daogawa           #+#    #+#             */
/*   Updated: 2025/11/03 20:19:24 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_recur(int n)
{
	char	c;
	int		ret;
	int		cnt;

	cnt = 0;
	if (n < 0)
	{
		if (write(1, "-", 1) != 1)
			return (-1);
		n = -n;
		cnt++;
	}
	if (n >= 10)
	{
		ret = ft_putnbr(n / 10);
		if (ret == -1)
			return (-1);
		cnt += ret;
	}
	c = (n % 10) + '0';
	if (write(1, &c, 1) != 1)
		return (-1);
	cnt++;
	return (cnt);
}

int	ft_putnbr(int n)
{
	if (n == -2147483648)
		return ((int)write(1, "-2147483648", 11));
	else
		return (ft_putnbr_recur(n));
}
