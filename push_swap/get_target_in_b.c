/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target_in_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:45:38 by daogawa           #+#    #+#             */
/*   Updated: 2025/12/19 18:30:10 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	init_move(t_move *move)
{
	move->ra = 0;
	move->rb = 0;
	move->rra = 0;
	move->rrb = 0;
	move->total = 0;
	move->number = -1;
}

void	set_move(t_move move, int min_cost, t_move *new_move)
{
	init_move(new_move);
	if (move.number == 0)
	{
		new_move->ra = move.ra;
		new_move->rb = move.rb;
	}
	else if (move.number == 1)
	{
		new_move->ra = move.ra;
		new_move->rrb = move.rrb;
	}
	else if (move.number == 2)
	{
		new_move->rra = move.rra;
		new_move->rb = move.rb;
	}
	else if (move.number == 3)
	{
		new_move->rra = move.rra;
		new_move->rrb = move.rrb;
	}
	new_move->number = move.number;
	new_move->total = min_cost;
}

static void	cost_calc(t_move *move, const t_stack *stack_a,
	const t_stack *stack_b, t_list *node)
{
	move->ra = from_top(stack_a, node);
	if (move->ra == 0)
		move->rra = 0;
	else
		move->rra = stack_a->size - move->ra;
	move->rb = from_top(stack_b, find_target_in_b(stack_b, node->index));
	if (move->rb == 0)
		move->rrb = 0;
	else
		move->rrb = stack_b->size - move->rb;
}

static t_move	calculate_move(const t_stack *stack_a,
	const t_stack *stack_b, t_list *node)
{
	t_move	move;
	int		cost[4];
	int		min_cost;
	int		i;
	t_move	new_move;

	cost_calc(&move, stack_a, stack_b, node);
	i = -1;
	min_cost = INT_MAX;
	cost[0] = max(move.ra, move.rb);
	cost[1] = move.ra + move.rrb;
	cost[2] = move.rra + move.rb;
	cost[3] = max(move.rra, move.rrb);
	while (++i < 4)
	{
		if (cost[i] < min_cost)
		{
			min_cost = cost[i];
			move.number = i;
			set_move(move, min_cost, &new_move);
		}
	}
	return (new_move);
}

t_move	get_target_in_b(const t_stack *stack_a, const t_stack *stack_b)
{
	t_list		*node;
	int			count;
	t_move		move;
	t_move		best_move;

	node = stack_a->top;
	count = INT_MAX;
	while (node)
	{
		move = calculate_move(stack_a, stack_b, node);
		if (count > move.total)
		{
			count = move.total;
			best_move = move;
		}
		node = node->next;
	}
	return (best_move);
}
