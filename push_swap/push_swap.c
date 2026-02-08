/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 22:24:00 by daogawa           #+#    #+#             */
/*   Updated: 2025/12/26 00:41:29 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	do_rot(t_stack *stack_a, t_stack *stack_b, t_move move)
{
	if (move.number == 0)
	{
		while (move.ra > 0 && move.rb > 0)
			(1) && (rr(stack_a, stack_b), move.ra--, move.rb--);
	}
	else if (move.number == 3)
	{
		while (move.rra > 0 && move.rrb > 0)
			(1) && (rrr(stack_a, stack_b), move.rra--, move.rrb--);
	}
	while (move.ra > 0 && move.ra--)
		rotate_up(stack_a, 1);
	while (move.rb > 0 && move.rb--)
		rotate_up(stack_b, 2);
	while (move.rra > 0 && move.rra--)
		rotate_down(stack_a, 1);
	while (move.rrb > 0 && move.rrb--)
		rotate_down(stack_b, 2);
}

void	push_tob(t_stack *stack_a, t_stack *stack_b)
{
	t_move		move;

	move = get_target_in_b(stack_a, stack_b);
	do_rot(stack_a, stack_b, move);
	push_b(stack_a, stack_b);
}

void	push_toa(t_stack *stack_a, t_stack *stack_b)
{
	t_move		move;

	while (stack_b->top)
	{
		move = get_target_in_a(stack_a, stack_b);
		do_rot(stack_a, stack_b, move);
		push_a(stack_a, stack_b);
	}
}

static void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 1)
		return ;
	if (stack_a->size == 2)
		return (sort_2(stack_a, 1));
	if (stack_a->size == 3)
		return (sort_3(stack_a));
	if (stack_a->size == 4)
		push_b(stack_a, stack_b);
	else
	{
		push_b(stack_a, stack_b);
		push_b(stack_a, stack_b);
		sort_2(stack_b, 0);
	}
	while (stack_a->size > 3)
	{
		push_tob(stack_a, stack_b);
	}
	sort_3(stack_a);
	push_toa(stack_a, stack_b);
	move_min_to_top(stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (1);
	}
	else
		argv++;
	if (check_args(argv) || is_duplicate(argv, argc))
		return (write(2, "Error\n", 6), 1);
	stack_a = stack_init_a(argv);
	stack_b = stack_init_b();
	if (stack_a == NULL || stack_b == NULL)
		return (write(2, "Error\n", 6), 1);
	add_index(stack_a);
	if (is_sorted(stack_a) == 0)
		return (free_all(stack_a, stack_b, argv, argc), 0);
	push_swap(stack_a, stack_b);
	free_all(stack_a, stack_b, argv, argc);
	return (0);
}
