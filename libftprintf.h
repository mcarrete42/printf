/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:12:10 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/13 18:58:15 by mcarrete         ###   ########.fr       */
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
	int		tilde;
	int		length;
	int		width;
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
void	ft_putptr_fd(unsigned long n, int fd);
int		is_width(int arg_int, char *str_int, va_list args, t_modifiers *flags);
char	*plus_space(int arg_int, char *str_int, t_modifiers *flags);
char	*zero_load(char *pad_char, int padding, int arg_int, t_modifiers *flags);
char	*is_precision(char *str_int, va_list args, t_modifiers *flags);




/*
** ------------------------PARSE CONVERSIONS ----------------------------------
*/

int		type_reader(char *str, int i, va_list args, t_modifiers *flags);
int		int_output(char str2_i, int i, va_list args, t_modifiers *flags);
int		u_output(char str2_i, int i, va_list args, t_list flags);
int 	nbr_reader(char str2_i, va_list args);
int		char_reader(char str_i, va_list args);


/*
** ------------------------------PARSE FLAGS-----------------------------------
*/

int		flag_parser(char *str2, int i, va_list args, t_modifiers *flags);
void	flag_reader(char *str2, t_modifiers *flags);
void	flags_initialiser(t_modifiers *flags);
int		ft_arg_cunter(char *str2);
void	flag_sum(t_modifiers *flags);
void	precision_definer(char *str2, va_list args, t_modifiers *flags);
void	width_definer(char *str2, va_list args, t_modifiers *flags);

#endif
