/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 23:22:24 by daogawa           #+#    #+#             */
/*   Updated: 2025/12/14 18:50:11 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_back(t_stack *stack, t_list *list)
{
	t_list	*old_list;

	if (!list || !stack)
		return ;
	list->next = NULL;
	if (stack->tail != NULL)
	{
		old_list = stack->tail;
		list->prev = old_list;
		old_list->next = list;
		stack->tail = list;
	}
	else
	{
		list->prev = NULL;
		stack->top = list;
		stack->tail = list;
	}
	return ;
}

void	push_front(t_stack *stack, t_list *list)
{
	if (!list || !stack)
		return ;
	list->prev = NULL;
	list->next = stack->top;
	if (stack->top != NULL)
		stack->top->prev = list;
	else
		stack->tail = list;
	stack->top = list;
	return ;
}

t_list	*pop(t_stack *stack)
{
	t_list	*list;
	t_list	*result;

	if (stack == NULL || stack->top == NULL)
		return (NULL);
	if (stack->size == 0)
		return (NULL);
	list = stack->top;
	if (stack->top->next == NULL)
	{
		stack->top = NULL;
		stack->tail = NULL;
		stack->size = 0;
		return (list);
	}
	result = list;
	list->next->prev = NULL;
	stack->top = list->next;
	stack->size--;
	return (result);
}

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*node;

	node = pop(stack_b);
	if (node == NULL)
		return ;
	if (stack_b != NULL && stack_b->size == 0)
	{
		stack_b = NULL;
	}
	push_front(stack_a, node);
	stack_a->size++;
	write(1, "pa\n", 3);
}

int	push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*node;

	node = pop(stack_a);
	if (node == NULL)
		return (1);
	if (stack_a != NULL && stack_a->size == 0)
	{
		stack_a = NULL;
	}
	push_front(stack_b, node);
	stack_b->size++;
	write(1, "pb\n", 3);
	return (0);
}
