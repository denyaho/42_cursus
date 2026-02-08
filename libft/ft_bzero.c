/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:49:47 by daogawa           #+#    #+#             */
/*   Updated: 2025/10/25 14:37:46 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			idx;
	unsigned char	*dest;

	idx = 0;
	dest = (unsigned char *)s;
	while (idx < n)
	{
		*dest++ = 0;
		idx++;
	}
}
