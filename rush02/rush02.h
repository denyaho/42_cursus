/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 12:21:06 by komatsuk          #+#    #+#             */
/*   Updated: 2025/09/21 16:30:12 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_dict
{
	char	key[256];
	char	value[1024];
}	t_dict;

extern t_dict	*g_dict;

int		ft_strlen(char *s);
void	ft_putstr(char *s);
void	ft_puterror(char *s);
char	*ft_strdup(char *src, int size);
void	initialize_ij(int *i, int *j);

t_dict	*malloc_dict(char *filename);
int		count_entry(int fd);
int		split_dict(t_dict *dict, int dict_i, char *s);
int		assign_dict(t_dict *dict, char *buf, int size);
int		get_dict(char *filename, t_dict *dict);

char	*get_n(char *s);
int		func(char *filename, char *n);

void	write_chunk(int cnt_zero, int digits, char *chunk);
void	handle_digits(int cnt_zero, int *digits);
void	create_pow_array(int cand, int cnt_zero, int *digits);
int		handle_case(char *str);
void	print_number(char *str);

void	put_by_key(char *str);
void	print_num(char *str);
void	print_ten(char *str);
void	print_handred(char *str);
void	write_str(char *str);

int		ft_strcmp(char *s1, char *s2);
int		find_key(char *str);
char	*make_pow(int num);
void	init_array(char *arr);
int		check_allzero(char *str, int size);

#endif