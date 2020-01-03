/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:12:10 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/02 19:36:40 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct 	s_modifiers
{
	int		i;
	int		len;
	int		minus;
	int		zero;
	int		precision;
	int		star;
	int 	hash;
	int		space;
	int		plus;
	int		length;
	int		width;
}			t_modifiers;

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
void	ft_putdouble_fd(double n, int fd);
void	ft_puthex_fd(int n, int fd);
void	ft_puthex_upper_fd(int n, int fd);
int		type_reader(char *str, int i, int j, va_list args, t_modifiers *flags);
int		int_reader(char *str, int j, va_list args);
int 	nbr_reader(char *str, int j, va_list args);
int		char_reader(char *str, int j, va_list args);
void	ft_putadress_fd(void *s, int fd);
int		flag_reader(char *str, int j, va_list args, t_modifiers *flags);
void	flags_initialiser(t_modifiers *flags);


#endif
