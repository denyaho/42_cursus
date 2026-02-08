/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:30:49 by daogawa           #+#    #+#             */
/*   Updated: 2025/10/24 19:36:37 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dst_cpy;
	const unsigned char	*src_cpy;

	if (dest == NULL && src == NULL)
		return (dest);
	dst_cpy = (unsigned char *)dest;
	src_cpy = (unsigned char *)src;
	if (dst_cpy < src_cpy)
	{
		while (n--)
		{
			*dst_cpy++ = *src_cpy++;
		}
	}
	else
	{
		dst_cpy += n;
		src_cpy += n;
		while (n--)
		{
			*--dst_cpy = *--src_cpy;
		}
	}
	return (dest);
}

// int main(void)
// {
// 	char *str;
// 	char src[4];

// 	str = (char *)malloc(sizeof(char) * 6);
// 	str[0] = 'S';
// 	str[1] = 'b';
// 	str[2] = 'd';
// 	str[3] = 'g';
// 	str[4] = 's';
// 	str[5] = '\0';

// 	src = str+2;
// 	src[0] = str[2];
// 	src[1] = str[3];
// 	src[2] = str[4];
// 	src[3] = str[5];
// 	printf("str is %s\n", str);
// 	printf("src is %s\n",src);
// 	memcpy(str,src,2);
// //	memmove(str,src, 4);
// 	printf("reulst str is %s",str);
// 	free(str);
// }
