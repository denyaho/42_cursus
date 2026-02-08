/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:55:23 by daogawa           #+#    #+#             */
/*   Updated: 2025/10/23 20:01:36 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char const *s, void (*f)(unsigned int, char *))
{
	size_t	idx;
	char	*str;

	idx = 0;
	str = (char *)s;
	while (str[idx])
	{
		f(idx, &str[idx]);
		idx++;
	}
}
