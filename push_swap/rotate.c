/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 23:20:59 by daogawa           #+#    #+#             */
/*   Updated: 2025/12/19 18:44:58 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate_up(t_stack *stack, int stack_n)
{
	t_list	*front_list;

	if (stack->size < 2)
		return ;
	front_list = stack->top;
	detach(stack, front_list);
	push_back(stack, front_list);
	if (stack_n == 1)
		write(1, "ra\n", 3);
	else if (stack_n == 2)
		write(1, "rb\n", 3);
	else
		return ;
}

void	rotate_down(t_stack *stack, int stack_n)
{
	t_list	*tail_list;

	if (stack->size < 2)
		return ;
	tail_list = stack->tail;
	detach(stack, tail_list);
	push_front(stack, tail_list);
	if (stack_n == 1)
		write(1, "rra\n", 4);
	else if (stack_n == 2)
		write(1, "rrb\n", 4);
	else
		return ;
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rotate_down(stack_a, 0);
	rotate_down(stack_b, 0);
	write(1, "rrr\n", 4);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate_up(stack_a, 0);
	rotate_up(stack_b, 0);
	write(1, "rr\n", 3);
}
