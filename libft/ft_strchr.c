/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 16:48:14 by daogawa           #+#    #+#             */
/*   Updated: 2025/10/25 14:54:37 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	idx;
	char	*ptr;

	idx = 0;
	ptr = (char *)s;
	if ((unsigned char)c == '\0')
		return (ptr + ft_strlen(s));
	while (s[idx] != '\0')
	{
		if ((unsigned char)s[idx] == (unsigned char)c)
		{
			return (ptr + idx);
		}
		idx++;
	}
	return (NULL);
}
