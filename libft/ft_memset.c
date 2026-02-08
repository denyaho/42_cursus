/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 20:04:11 by daogawa           #+#    #+#             */
/*   Updated: 2025/10/22 20:44:36 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*dst;
	unsigned char	uc;
	size_t			idx;

	dst = (unsigned char *)s;
	uc = (unsigned char)c;
	idx = 0;
	while (idx < n)
	{
		*dst++ = uc;
		idx++;
	}
	return (s);
}

// int	main(void)
// {
// 	int	s[5];
// 	int	t[5];

// 	s[0] = 1;
// 	s[1] = 3;
// 	s[2] = 4;
// 	s[3] = 3;
// 	s[4] = 3;
// 	t[0] = 1;
// 	t[1] = 3;
// 	t[2] = 4;
// 	t[3] = 3;
// 	t[4] = 3;

// 	memset(s, -3,4);
// 	ft_memset(t,-3,4);
// 	for(int i=0;i<5;i++)
// 	{
// 		printf("%d\n",s[i]);
// 	}
// 	for(int i=0;i<5;i++)
// 	{
// 		printf("%d\n",t[i]);
// 	}
// }
