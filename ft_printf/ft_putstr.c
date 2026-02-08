/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:56:15 by daogawa           #+#    #+#             */
/*   Updated: 2025/11/02 18:03:49 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	if (str == NULL)
	{
		if (write(1, "(null)", 6) != 6)
			return (-1);
		return (6);
	}
	return ((int)write(1, str, ft_strlen(str)));
}
