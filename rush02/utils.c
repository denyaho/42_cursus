/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 13:31:46 by komatsuk          #+#    #+#             */
/*   Updated: 2025/09/21 16:13:57 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

void	ft_puterror(char *s)
{
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}

void	initialize_ij(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

char	*ft_strdup(char *src, int size)
{
	char	*ans;
	int		idx;

	if (size == 0)
		return (NULL);
	ans = (char *)malloc(sizeof(char) * (size + 1));
	if (ans == NULL)
		return (NULL);
	idx = 0;
	while (idx < size)
	{
		ans[idx] = src[idx];
		idx++;
	}
	ans[idx] = '\0';
	return (ans);
}
