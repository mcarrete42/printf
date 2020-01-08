/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:12:10 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/07 21:41:24 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** -------------------------------FLAGS STRUCT---------------------------------
*/

typedef struct 	s_modifiers
{
	char	*strtoformat;
	int		i;
	int		len;
	int		minus;
	int		zero;
	int		precision;
	int		is_precision;
	int		star;
	int 	hash;
	int		space;
	int		plus;
	int		length;
	int		width;
	int		is_width;
}			t_modifiers;

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define CONVANDFLAGS "cspdiouxXfyb%-0.*#’ +lh0123456789"
# define FLAGS "-0.*#’ +lh0123456789"
# define CONVERSIONS "cspdiouxXfyb%"

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

/*
** -----------------------------------PRINTF-----------------------------------
*/

int		ft_printf(const char *str, ...);

/*
** ---------------------PRINT OUTPUT OF CONVERSIONS + FLAGS--------------------
*/

int		conversions(char str2_i, int i, va_list args, t_modifiers *flags);
void	ft_putdouble_fd(double n, int fd);
void	ft_puthex_fd(int n, int fd);
void	ft_puthex_upper_fd(int n, int fd);
void	ft_putadress_fd(void *s, int fd);
void	ft_putptr_fd(int n, int fd);

/*
** ------------------------PARSE CONVERSIONS ONLY------------------------------
*/

int		type_reader(char *str, int i, va_list args, t_modifiers *flags);
int		int_output(char str2_i, int i, va_list args, t_modifiers *flags);
int 	nbr_reader(char str2_i, va_list args);
int		char_reader(char str_i, va_list args);


/*
** ------------------------------PARSE FLAGS-----------------------------------
*/

int		flag_parser(char *str2, int i, va_list args, t_modifiers *flags);
int		flag_reader(char *str2, int i, t_modifiers *flags);
void	flags_initialiser(t_modifiers *flags);
int		ft_arg_cunter(char *str2);
void	flag_sum(t_modifiers *flags);
void	precision_definer(char *str2, int i, va_list args, t_modifiers *flags);
void	width_definer(char str2_i, t_modifiers *flags);

#endif
