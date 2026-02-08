/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 09:33:12 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/09/24 10:31:26 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	int		number_row;
	char	empty;
	char	obstacle;
	char	full;
}			t_map;

// dynamic_cal.c
int			**convert_char_int(char **map, t_map element, int x);
int			**dynamic_cal(int **map, int y, int x);
int			find_min(int **map, int y, int x);
int			search_square(char **map, t_map element);
// ft_putchar.c
void		ft_putchar(char c);
// map_length.c
int			x_length(char **map);
void		free_convert_map(int **map, t_map element);
void		free_map(char **map, t_map element);
// reflection_map.c
void		reflection_map(char **original_map, int **convert_map,
				t_map element, int *square);
int			*find_max_xy(char **original_map, int **convert_map, int *square,
				t_map element);
int			find_max_value(char **original_map, int **convert_map,
				t_map element);

#endif
