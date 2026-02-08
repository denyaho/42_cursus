/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:09:34 by daogawa           #+#    #+#             */
/*   Updated: 2025/10/24 21:00:58 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	real_len(char const *s, unsigned int start, size_t len)
{
	size_t	len_t;

	len_t = 0;
	while (s[start + len_t] && len_t < len)
	{
		len_t++;
	}
	return (len_t);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	idx;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		substr = (char *)malloc(sizeof(char));
		if (substr == NULL)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	idx = 0;
	substr = (char *)malloc(sizeof(char) * (real_len(s, start, len) + 1));
	if (substr == NULL)
		return (NULL);
	while (s[start + idx] && idx < len)
	{
		substr[idx] = s[idx + start];
		idx++;
	}
	substr[idx] = '\0';
	return (substr);
}
