/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 21:47:03 by daogawa           #+#    #+#             */
/*   Updated: 2025/12/26 05:40:01 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_list
{
	int				data;
	int				index;
	int				flag; //0ならUP, 1ならDOWN
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_stack
{
	t_list	*top;//入口がtop
	t_list	*tail;//底がtail
	int		size;
}	t_stack;

typedef struct s_rot
{
	int	count;
	int	dir;
}	t_rot;

typedef struct s_list_dir
{
	int	data;
	int	count;
	int	dir;
}	t_list_dir;

typedef struct s_move
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	total;
	int	number;
}	t_move;

void		detach(t_stack *stack, t_list *list);
t_list		*find_target_in_b(const t_stack *stack_b, int index);
t_list		*find_target_in_a(const t_stack *stack_a, int index);
long		ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
int			ft_lstsize(t_list *lst);
t_move		get_target_in_b(const t_stack *stack_a, const t_stack *stack_b);
void		add_index(t_stack *stack);
t_list		*ft_lstnew(int data);
int			push_b(t_stack *stack_a, t_stack *stack_b);
void		push_a(t_stack *stack_a, t_stack *stack_b);
t_list		*pop(t_stack *stack);
void		rotate_up(t_stack *stack, int stack_n);
void		rotate_down(t_stack *stack, int stack_n);
void		rr(t_stack *stack_a, t_stack *stack_b);
void		rrr(t_stack *stack_a, t_stack *stack_b);
void		sort_2(t_stack *stack, int s);
void		move_node_b(t_stack *stack_a, t_stack *stack_b);
void		sort_3(t_stack *stack_a);
void		sort_a(t_stack *stack_a, t_stack *stack_b);
int			check_args(char **argv);
t_stack		*stack_init_a(char **argv);
t_stack		*stack_init_b(void);
void		swap_a(t_stack *stack);
void		swap_b(t_stack *stack);
void		push_front(t_stack *stack, t_list *list);
void		push_back(t_stack *stack, t_list *list);
t_list_dir	count_to_top(const t_stack *stack, t_list *node);
int			ft_isdigit(int c);
void		sort_b(t_stack *stack_b);
t_list		*find_max_node(const t_stack *stack_b);
t_list		*find_min_node(const t_stack *stack);
void		sort_5(t_stack *stack_a, t_stack *stack_b);
int			is_duplicate(char **argv, int argc);
void		free_all(t_stack *stack_a, t_stack *stack_b, char **argv, int argc);
void		push_toa(t_stack *stack_a, t_stack *stack_b);
void		push_tob(t_stack *stack_a, t_stack *stack_b);
void		move_min_to_top(t_stack *stack_a);
int			max(int a, int b);
void		init_move(t_move *move);
void		set_move(t_move move, int min_cost, t_move *new_move);
t_move		get_target_in_a(const t_stack *stack_a, const t_stack *stack_b);
int			from_tail(const t_stack *stack, const t_list *node);
int			from_top(const t_stack *stack, const t_list *node);
int			is_sorted(t_stack *stack);
size_t		ft_strlen(const char *s);
void		free_split_argv(char **argv);
void		ft_lstclear(t_list **lst);

#endif
