/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:18:58 by daogawa           #+#    #+#             */
/*   Updated: 2025/12/21 16:13:50 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	is_overflow(long result, int sign, char next_char)
{
	if (sign == 1)
	{
		if (result > LONG_MAX / 10
			|| (result == LONG_MAX / 10
				&& LONG_MAX % 10 < (next_char - '0')))
			return (1);
	}
	else if (sign == -1)
	{
		if (LONG_MIN / -10 < result
			|| (result == LONG_MIN / -10
				&& LONG_MIN % 10 > - (next_char - '0')))
			return (-1);
	}
	return (0);
}

long	ft_atoi(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	if (!ft_isdigit(*str))
		return (2147483648L);
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		if (sign * result > INT_MAX || sign * result < INT_MIN)
			return (2147483648L);
		str++;
	}
	if (*str != '\0' )
		return (2147483648L);
	return (result * sign);
}
