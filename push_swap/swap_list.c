/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 21:56:39 by daogawa           #+#    #+#             */
/*   Updated: 2025/12/14 18:53:43 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	swap(t_stack *stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	third = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third)
		third->prev = first;
	else
		stack->tail = first;
	stack->top = second;
}

void	swap_a(t_stack *stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack *stack)
{
	swap(stack);
	write(1, "sb\n", 3);
}
