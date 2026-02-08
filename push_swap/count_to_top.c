/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_to_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:20:37 by daogawa           #+#    #+#             */
/*   Updated: 2025/12/19 18:45:36 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	from_top(const t_stack *stack, const t_list *node)
{
	t_list	*tmp;
	int		count;

	if (stack == NULL || node == NULL)
		return (-1);
	tmp = stack->top;
	count = 0;
	while (tmp)
	{
		if (tmp == node)
			return (count);
		tmp = tmp->next;
		count++;
	}
	return (-1);
}

int	from_tail(const t_stack *stack, const t_list *node)
{
	t_list	*tmp;
	int		count;

	if (stack == NULL || node == NULL)
		return (-1);
	count = 1;
	tmp = stack->tail;
	while (tmp)
	{
		if (tmp == node)
			return (count);
		tmp = tmp->prev;
		count++;
	}
	return (-1);
}

t_list_dir	count_to_top(const t_stack *stack, t_list *node)
{
	t_list_dir	target;
	int			count1;
	int			count2;

	count1 = from_top(stack, node);
	count2 = from_tail(stack, node);
	target.data = -1;
	if (count1 == -1 || count2 == -1)
	{
		target.count = -1;
		target.dir = -1;
		return (target);
	}
	if (count1 < count2)
	{
		target.count = count1;
		target.dir = 0;
	}
	else
	{
		target.count = count2;
		target.dir = 1;
	}
	return (target);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
