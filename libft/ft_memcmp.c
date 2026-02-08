/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:23:33 by daogawa           #+#    #+#             */
/*   Updated: 2025/10/22 20:44:36 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const char *s1, const char *s2, size_t n)
{
	size_t			idx;
	unsigned char	us1;
	unsigned char	us2;

	idx = 0;
	while (idx < n)
	{
		us1 = (unsigned char)s1[idx];
		us2 = (unsigned char)s2[idx];
		if (us1 != us2)
		{
			return (us1 - us2);
		}
		idx++;
	}
	return (0);
}

// int main(void)
// {
// 	char *s1 = "Hello world";
// 	char *s2 = "Hello wosrld";

// 	printf("result of memcmp is %d\n", memcmp(s1,s2,15));
// 	printf("result of ft_memcmp is %d\n", ft_memcmp(s1,s2,15));
// }
