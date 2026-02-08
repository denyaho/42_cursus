/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 12:22:42 by komatsuk          #+#    #+#             */
/*   Updated: 2025/09/21 16:28:29 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

t_dict	*g_dict;

int	main(int argc, char *argv[])
{
	int		res;
	char	*n;

	res = 0;
	if (argc == 1)
		return (1);
	n = get_n(argv[argc - 1]);
	if (n == NULL)
	{
		ft_puterror("Error");
		return (1);
	}
	if (argc == 2)
		res = func("source/numbers.dict", n);
	else if (argc == 3)
		res = func(argv[1], n);
	else
		return (1);
	return (res);
}
