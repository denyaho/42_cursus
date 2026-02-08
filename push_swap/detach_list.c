/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detach_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 22:55:56 by daogawa           #+#    #+#             */
/*   Updated: 2025/12/14 18:40:05 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	detach(t_stack *stack, t_list *list)
{
	if (list->prev != NULL)
		list->prev->next = list->next;
	else
		stack->top = list->next;
	if (list->next != NULL)
		list->next->prev = list->prev;
	else
		stack->tail = list->prev;
	list->prev = NULL;
	list->next = NULL;
}
