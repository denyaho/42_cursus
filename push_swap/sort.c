/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:26:04 by daogawa           #+#    #+#             */
/*   Updated: 2025/12/21 15:52:31 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_2(t_stack *stack, int s)
{
	t_list	*first;
	t_list	*second;

	if (stack == NULL || stack->size != 2)
		return ;
	first = stack->top;
	second = stack->tail;
	if (first->index > second->index)
	{
		if (s == 1)
			return (swap_a(stack));
		else
			return (swap_b(stack));
	}
	return ;
}

void	sort_b(t_stack *stack_b)
{
	t_list		*max_node;
	t_list_dir	move;

	max_node = find_max_node(stack_b);
	if (max_node == NULL)
		return ;
	move = count_to_top(stack_b, max_node);
	if (move.count == -1)
		return ;
	if (move.dir == 0)
	{
		while (move.count-- > 0)
			rotate_up(stack_b, 2);
	}
	else
	{
		while (move.count-- > 0)
			rotate_down(stack_b, 2);
	}
}

void	sort_3(t_stack *stack_a)
{
	int	x;
	int	y;
	int	z;

	if (stack_a == NULL || stack_a->size != 3)
		return ;
	x = stack_a->top->index;
	y = stack_a->top->next->index;
	z = stack_a->top->next->next->index;
	if (x > y && y < z && x < z)
		swap_a(stack_a);
	else if (x > y && y > z)
	{
		swap_a(stack_a);
		rotate_down(stack_a, 1);
	}
	else if (x > y && y < z && x > z)
		rotate_up(stack_a, 1);
	else if (x < y && y > z && x < z)
	{
		swap_a(stack_a);
		rotate_up(stack_a, 1);
	}
	else if (x < y && y > z && x > z)
		rotate_down(stack_a, 1);
}

void	sort_a(t_stack *stack_a, t_stack *stack_b)
{
	t_list_dir	move;
	t_list		*target;

	target = find_target_in_a(stack_a, stack_b->top->index);
	if (target == NULL)
		return ;
	if (target)
	{
		move = count_to_top(stack_a, target);
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
}
