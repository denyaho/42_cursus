/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:35:33 by daogawa           #+#    #+#             */
/*   Updated: 2025/10/28 23:24:01 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

size_t	ft_strlen(char *s);
int		ft_putstr(char	*s);
int		ft_putchar(int n);
int		ft_putptr(void *str);
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int n);
int		ft_puthex(unsigned int n);
int		ft_puthex_big(unsigned int n);
int		ft_printf(const char *format, ...);

#endif
