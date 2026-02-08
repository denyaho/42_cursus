/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:10:22 by daogawa           #+#    #+#             */
/*   Updated: 2025/10/25 14:57:14 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			idx;
	unsigned char	us1;
	unsigned char	us2;

	idx = 0;
	while ((s1[idx] != '\0' || s2[idx] != '\0') && idx < n)
	{
		us1 = (unsigned char)s1[idx];
		us2 = (unsigned char)s2[idx];
		if (us1 != us2)
		{
			return (us1 - us2);
		}
		idx++;
	}
	return (0);
}
