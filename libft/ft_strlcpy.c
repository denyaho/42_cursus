/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 10:45:12 by daogawa           #+#    #+#             */
/*   Updated: 2025/10/25 14:56:43 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char			*d;
	char			*s;
	size_t			n;

	s = (char *)src;
	d = dst;
	n = size;
	if (n != 0)
	{
		while (--n != 0)
		{
			*d = *s;
			if (*s == '\0')
				break ;
			d++;
			s++;
		}
	}
	if (n == 0)
	{
		if (size != 0)
			*d = '\0';
	}
	return (ft_strlen(src));
}
