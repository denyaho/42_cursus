/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:05:17 by daogawa           #+#    #+#             */
/*   Updated: 2025/10/23 19:58:30 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src_cpy;
	unsigned char	uc;
	size_t			idx;

	idx = 0;
	uc = (unsigned char)c;
	src_cpy = (unsigned char *)s;
	while (idx < n)
	{
		if (src_cpy[idx] == uc)
			return (src_cpy + idx);
		idx++;
	}
	return (NULL);
}

// int main(void)
// {
// 	char *str = "Hello World";
// 	char c = 's';

// 	printf("Result is %p\n", memchr(str, c, 15));
// 	printf("Result is %p\n", ft_memchr(str, c, 15));
// }
