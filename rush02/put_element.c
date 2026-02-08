/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 12:47:16 by daogawa           #+#    #+#             */
/*   Updated: 2025/09/21 16:28:46 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	put_by_key(char *str)
{
	int	idx;

	idx = 0;
	while (g_dict[idx].key[0] != '\0')
	{
		if (ft_strcmp(g_dict[idx].key, str) == 0)
		{
			write(1, " ", 1);
			write(1, g_dict[idx].value, ft_strlen(g_dict[idx].value));
			break ;
		}
		idx++;
	}
}

void	print_num(char *str)
{
	char	number[2];

	number[0] = str[0];
	number[1] = '\0';
	put_by_key(number);
	return ;
}

void	print_ten(char *str)
{
	char	number[3];

	if (find_key(str) == 0)
	{
		put_by_key(str);
		return ;
	}
	number[0] = str[0];
	number[1] = '0';
	number[2] = '\0';
	put_by_key(number);
	put_by_key(&str[1]);
	return ;
}

void	print_handred(char *str)
{
	char	number[2];
	char	*handred;

	handred = "100";
	if (str[0] == '0' && str[1] == '0')
	{
		print_num(&str[2]);
		return ;
	}
	else if (str[0] == '0' && str[1] != '0')
	{
		print_ten(&str[1]);
		return ;
	}
	number[0] = str[0];
	number[1] = '\0';
	put_by_key(number);
	put_by_key(handred);
	if (str[1] != '0')
		print_ten(&str[1]);
	else if (str[2] != '0')
		print_num(&str[2]);
	return ;
}

void	write_str(char *str)
{
	if (ft_strlen(str) == 3)
		print_handred(str);
	else if (ft_strlen(str) == 2)
		print_ten(str);
	else if (ft_strlen(str) == 1)
		print_num(str);
	return ;
}
