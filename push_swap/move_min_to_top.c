/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:12:53 by daogawa           #+#    #+#             */
/*   Updated: 2025/12/19 18:45:12 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	move_min_to_top(t_stack *stack_a)
{
	t_list		*min_node;
	t_list_dir	move;

	min_node = find_min_node(stack_a);
	if (min_node == NULL)
		return ;
	move = count_to_top(stack_a, min_node);
	if (move.dir == 0)
	{
		while (move.count-- > 0)
			rotate_up(stack_a, 1);
	}
	else
	{
		while (move.count-- > 0)
			rotate_down(stack_a, 1);
	}
}
