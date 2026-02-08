/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:59:44 by daogawa           #+#    #+#             */
/*   Updated: 2025/11/02 18:03:37 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr_rec(unsigned int n)
{
	char	c;
	int		ret;
	int		cnt;

	cnt = 0;
	if (n >= 10)
	{
		ret = ft_putunbr_rec(n / 10);
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

int	ft_putunbr(unsigned int n)
{
	return (ft_putunbr_rec(n));
}
