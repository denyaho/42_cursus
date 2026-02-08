/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 21:02:28 by daogawa           #+#    #+#             */
/*   Updated: 2025/10/25 14:54:41 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t		len;
	char		*ans;
	size_t		idx;

	len = 0;
	while (src[len] != '\0')
		len++;
	ans = (char *)malloc(sizeof(char) * (len + 1));
	if (ans == NULL)
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		ans[idx] = src[idx];
		idx++;
	}
	ans[idx] = '\0';
	return (ans);
}
