/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:58:09 by daogawa           #+#    #+#             */
/*   Updated: 2025/10/25 14:56:53 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t ft_strlen(char const *str)
// {
// 	size_t size;

// 	size = 0;
// 	while(str[size])
// 	{
// 		size++;
// 	}
// 	return (size);
// }

char	*ft_strrchr(const char *s, int c)
{
	size_t	idx;
	char	*ptr;
	int		flag;
	size_t	place;

	idx = 0;
	flag = 0;
	ptr = (char *)s;
	if ((unsigned char)c == '\0')
		return (ptr + ft_strlen(s));
	while (s[idx] != '\0')
	{
		if ((unsigned char)s[idx] == (unsigned char)c)
		{
			place = idx;
			flag = 1;
		}
		idx++;
	}
	if (flag)
		return (ptr + place);
	return (NULL);
}
