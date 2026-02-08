/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 05:51:41 by daogawa           #+#    #+#             */
/*   Updated: 2025/10/24 21:00:37 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	idx;
	size_t	little_len;
	size_t	idx_little;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	idx = 0;
	while (big[idx] && idx < len)
	{
		idx_little = 0;
		while (big[idx + idx_little] == little[idx_little]
			&& idx + idx_little < len)
		{
			if (little[idx_little + 1] == '\0')
				return ((char *)big + idx);
			idx_little++;
		}
		idx++;
	}
	return (NULL);
}
