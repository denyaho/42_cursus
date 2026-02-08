/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 06:27:38 by daogawa           #+#    #+#             */
/*   Updated: 2025/10/25 14:54:51 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_cpy;
	size_t	idx;

	size_cpy = ft_strlen(dst);
	idx = 0;
	while ((size_cpy + idx + 1) < size && *(src + idx) != '\0')
	{
		*(dst + size_cpy + idx) = *(src + idx);
		idx++;
	}
	*(dst + size_cpy + idx) = '\0';
	if (size <= size_cpy)
	{
		return (ft_strlen(src) + size);
	}
	return (ft_strlen(src) + size_cpy);
}
