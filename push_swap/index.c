/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 23:24:57 by daogawa           #+#    #+#             */
/*   Updated: 2025/12/26 05:51:20 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	assign_index(t_list *lst, int index, int val)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->index == -1 && tmp->data == val)
			break ;
		tmp = tmp->next;
	}
	if (tmp)
		tmp->index = index;
}

static int	get_min(t_list *lst)
{
	t_list		*tmp;
	long int	min;

	min = LONG_MAX;
	tmp = lst;
	while (tmp)
	{
		if (tmp->index == -1 && tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return ((int)min);
}

void	add_index(t_stack *stack)
{
	int	size;
	int	min;
	int	idx;

	size = ft_lstsize(stack->top);
	idx = 1;
	while (idx <= size)
	{
		min = get_min(stack->top);
		assign_index(stack->top, idx, min);
		idx++;
	}
}
