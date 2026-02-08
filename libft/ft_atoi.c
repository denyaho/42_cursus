/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:18:58 by daogawa           #+#    #+#             */
/*   Updated: 2025/10/24 21:00:25 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int	ft_atoi(const char *str)
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
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			break ;
		if (is_overflow(result, sign, *str) == 1)
			return ((int)LONG_MAX);
		else if (is_overflow(result, sign, *str) == -1)
			return ((int)LONG_MIN);
		result = result * 10 + (*str - '0');
		str++;
	}
	return ((int)(result * sign));
}
