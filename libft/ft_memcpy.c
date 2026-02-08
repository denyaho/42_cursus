/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:25:16 by daogawa           #+#    #+#             */
/*   Updated: 2025/10/24 19:36:47 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dst_cpy;
	const unsigned char	*src_cpy;
	size_t				idx;

	if (dest == NULL && src == NULL)
		return (dest);
	idx = 0;
	dst_cpy = (unsigned char *)dest;
	src_cpy = (unsigned char *)src;
	while (idx < n)
	{
		*dst_cpy++ = *src_cpy++;
		idx++;
	}
	return (dest);
}

// int main(void)
// {
// 	char *str;
// 	const char *src = "Hello";

// 	str = (char *)malloc(sizeof(char) * 6);
// 	str[0] = 'S';
// 	str[1] = 'b';
// 	str[2] = 'd';
// 	str[3] = 'g';
// 	str[4] = 's';
// 	str[5] = '\0';
// //	memcpy(str,src,3);
// 	ft_memcpy(str,src,3);
// 	printf("string str is %s",str);
// }
