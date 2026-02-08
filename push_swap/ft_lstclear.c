/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:47:38 by daogawa           #+#    #+#             */
/*   Updated: 2025/12/26 05:39:46 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_split_argv(char **argv)
{
	int	idx;

	idx = 0;
	while (argv[idx])
	{
		free(argv[idx]);
		idx++;
	}
	free(argv);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*current;
	t_list	*next;

	if (lst == NULL)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}

void	free_all(t_stack *stack_a, t_stack *stack_b, char **argv, int argc)
{
	ft_lstclear(&stack_a->top);
	ft_lstclear(&stack_b->top);
	free(stack_a);
	free(stack_b);
	if (argc == 2)
		free_split_argv(argv);
}
