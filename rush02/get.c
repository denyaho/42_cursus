/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:14:50 by komatsuk          #+#    #+#             */
/*   Updated: 2025/09/21 16:28:19 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*get_n(char *s)
{
	int	i;

	if (s[0] == '0' && s[1] != '\0')
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || '9' < s[i])
			return (NULL);
		i++;
	}
	return (s);
}

int	func(char *filename, char *n)
{
	g_dict = malloc_dict(filename);
	if (g_dict == NULL)
		return (1);
	if (get_dict(filename, g_dict))
		return (1);
	print_number(n);
	write(1, "\n", 1);
	free(g_dict);
	return (0);
}
