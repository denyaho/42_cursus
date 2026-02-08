/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:41:35 by daogawa           #+#    #+#             */
/*   Updated: 2025/10/25 14:57:02 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlen(char const *str)
// {
// 	size_t size;

// 	size = 0;
// 	while(str[size])
// 		size++;
// 	return (size);
// }
size_t	size_nbr(int n)
{
	size_t	size;
	long	n_cpy;

	size = 0;
	n_cpy = n;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		size++;
		n_cpy *= -1;
	}
	while (n_cpy > 0)
	{
		n_cpy /= 10;
		size++;
	}
	return (size);
}

char	*reverse_str(char *str, int n)
{
	size_t	left;
	size_t	right;
	char	tmp;

	left = 0;
	right = ft_strlen(str) - 1;
	if (n < 0)
		left = 1;
	while (left < right)
	{
		tmp = str[left];
		str[left] = str[right];
		str[right] = tmp;
		left++;
		right--;
	}
	return (str);
}

void	put_char(char *str, long n)
{
	size_t	idx;

	idx = 0;
	if (n < 0)
	{
		str[0] = '-';
		idx++;
		n *= -1;
	}
	while (n > 0)
	{
		str[idx] = n % 10 + '0';
		n /= 10;
		idx++;
	}
	str[idx] = '\0';
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*str;

	size = size_nbr(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	put_char(str, (long)n);
	return (reverse_str(str, n));
}
