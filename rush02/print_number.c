/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:39:47 by daogawa           #+#    #+#             */
/*   Updated: 2025/09/21 16:28:36 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	write_chunk(int cnt_zero, int digits, char *chunk)
{
	int		cnt_zero2;
	char	*copy;

	write_str(chunk);
	cnt_zero2 = cnt_zero - digits;
	if (cnt_zero2 > 0)
	{
		copy = make_pow(cnt_zero2);
		if (copy && find_key(copy) == 0)
		{
			put_by_key(copy);
			free(copy);
		}
	}
	return ;
}

void	handle_digits(int cnt_zero, int *digits)
{
	*digits = cnt_zero % 3;
	if (*digits == 0)
		*digits = 3;
	return ;
}

void	create_pow_array(int cand, int cnt_zero, int *digits)
{
	char	*copy;

	while (++cand <= 3 && cnt_zero > 3)
	{
		if (cnt_zero - cand < 0)
			break ;
		copy = make_pow(cnt_zero - cand);
		if (copy && find_key(copy) == 0)
		{
			*digits = cand;
			break ;
		}
		free(copy);
	}
	return ;
}

int	handle_case(char *str)
{
	if (ft_strlen(str) == 0)
		return (1);
	if (find_key(str) == 0)
	{
		put_by_key(str);
		return (1);
	}
	return (0);
}

void	print_number(char *str)
{
	int		cnt_zero;
	int		digits;
	int		cand;
	int		idx;
	char	*chunk;

	if (handle_case(str))
		return ;
	idx = 0;
	cnt_zero = ft_strlen(str);
	while (cnt_zero > 0)
	{
		digits = 0;
		cand = 0;
		create_pow_array(cand, cnt_zero, &digits);
		if (digits == 0)
			handle_digits(cnt_zero, &digits);
		chunk = ft_strdup(str + idx, digits);
		if (chunk && !check_allzero(chunk, digits))
			write_chunk(cnt_zero, digits, chunk);
		free(chunk);
		idx += digits;
		cnt_zero -= digits;
	}
}
