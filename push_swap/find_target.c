/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:11:35 by daogawa           #+#    #+#             */
/*   Updated: 2025/12/14 22:09:05 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*find_min_node(const t_stack *stack)
{
	t_list	*tmp;
	t_list	*min_node;

	min_node = NULL;
	tmp = stack->top;
	min_node = stack->top;
	while (tmp)
	{
		if (tmp->index < min_node->index)
			min_node = tmp;
		tmp = tmp->next;
	}
	return (min_node);
}

t_list	*find_max_node(const t_stack *stack_b)
{
	t_list	*tmp;
	t_list	*max_node;

	max_node = NULL;
	tmp = stack_b->top;
	max_node = stack_b->top;
	while (tmp)
	{
		if (tmp->index > max_node->index)
			max_node = tmp;
		tmp = tmp->next;
	}
	return (max_node);
}

//
t_list	*find_target_in_b(const t_stack *stack_b, int index)
{
	t_list	*tmp;
	t_list	*target;

	if (stack_b == NULL || stack_b->size == 0)
		return (NULL);
	target = NULL;
	tmp = stack_b->top;
	while (tmp)
	{
		if (tmp->index < index)
		{
			if (target == NULL || tmp->index > target->index)
				target = tmp;
		}
		tmp = tmp->next;
	}
	if (target)
		return (target);
	return (find_max_node(stack_b));
}

t_list	*find_target_in_a(const t_stack *stack_a, int index)
{
	t_list	*tmp;
	t_list	*target;

	if (stack_a == NULL || stack_a->size == 0)
		return (NULL);
	target = NULL;
	tmp = stack_a->top;
	while (tmp)
	{
		if (tmp->index > index)
		{
			if (target == NULL || tmp->index < target->index)
				target = tmp;
		}
		tmp = tmp->next;
	}
	if (target)
		return (target);
	return (find_min_node(stack_a));
}
