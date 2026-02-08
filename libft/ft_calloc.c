/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:23:19 by daogawa           #+#    #+#             */
/*   Updated: 2025/10/23 19:59:02 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned char	*p;
	size_t			idx;

	idx = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb * size > INT_MAX)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	p = (unsigned char *)ptr;
	while (idx < nmemb * size)
	{
		p[idx] = 0;
		idx++;
	}
	return (ptr);
}
