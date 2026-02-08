/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 20:46:34 by daogawa           #+#    #+#             */
/*   Updated: 2025/12/29 02:31:16 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_args(char **argv)
{
	int			idx;
	long long	num;

	idx = 0;
	while (argv[idx])
	{
		if (ft_strlen(argv[idx]) == 1
			&& (argv[idx][0] == '-' || argv[idx][0] == '+'))
			return (free_split_argv(argv), 1);
		num = ft_atoi(argv[idx]);
		if (num == 2147483648L)
			return (free_split_argv(argv), 1);
		idx++;
	}
	return (0);
}

t_stack	*stack_init_a(char **argv)
{
	t_stack		*stack;
	int			idx;
	long long	num;
	t_list		*new_node;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	*stack = (t_stack){0};
	idx = 0;
	while (argv[idx])
	{
		num = ft_atoi(argv[idx]);
		new_node = ft_lstnew((int)num);
		if (new_node == NULL)
		{
			ft_lstclear(&(stack->top));
			return (free(stack), NULL);
		}
		push_back(stack, new_node);
		stack->size++;
		idx++;
	}
	return (stack);
}

t_stack	*stack_init_b(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->top = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (stack);
}

int	is_sorted(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->top;
	while (tmp && tmp->next)
	{
		if (tmp->index > tmp->next->index)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
