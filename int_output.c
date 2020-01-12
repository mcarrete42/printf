/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:24:59 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/12 21:22:26 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		int_output(char str2_i, int i, va_list args, t_modifiers *flags)
{
	char	*str_int;
	int		arg_int;

	arg_int = va_arg(args, int);
	str_int = ft_itoa(arg_int);
	if (flags->is_precision == 1)
		str_int = is_precision(str_int, args, flags);
	if (flags->width > ft_strlen(str_int))
		is_width(arg_int, str_int, args, flags);
	else
		ft_putstr_fd(str_int, 1);
	return (0);
}

char	*is_precision(char *str_int, va_list args, t_modifiers *flags)
{
	char	*pad_zero;
	int		zero_num;
	if (flags->precision <= ft_strlen(str_int))
		return (str_int);
	zero_num = flags->precision - ft_strlen(str_int);
	if(!(pad_zero = malloc(sizeof(char) * zero_num)))
		return (NULL);
	ft_bzeroes(pad_zero, zero_num);
	str_int = ft_strjoin(pad_zero, str_int);
	free(pad_zero);
	return(str_int);
}

int		is_width(int arg_int, char *str_int, va_list args, t_modifiers *flags)
{
	int padding;
	char *pad_char;
	char *str_join;

	padding = flags->width - ft_strlen(str_int);
	if ((flags->plus == 1 && flags->zero == 0) ||
		(flags->space == 1 && flags->zero == 0))
	{
		padding = padding - 1;
		str_int = plus_space(arg_int, str_int, flags);
	}
	if(!(pad_char = malloc(sizeof(char) * padding)))
		return(0);
	pad_char = zero_load(pad_char, padding, arg_int, flags);
	if (flags->minus == 0)
		str_join = ft_strjoin(pad_char, str_int);
	else if (flags->minus == 1)
		str_join = ft_strjoin(str_int, pad_char);
	ft_putstr_fd(str_join, 1);
	free(pad_char);
	return (0);
}

char	*plus_space(int arg_int, char *str_int, t_modifiers *flags)
{
	if (arg_int >= 0 && flags->plus == 1)
		str_int = ft_strjoin("+", str_int);
	else if (arg_int >= 0 && flags->space == 1 && flags->zero == 0)
		str_int = ft_strjoin(" ", str_int);
	return (str_int);
}

char	*zero_load(char *pad_char, int padding, int arg_int, t_modifiers *flags)
{
	if (flags->zero == 0)
		ft_bspace(pad_char, padding);
	else if (flags->zero == 1)
		ft_bzeroes(pad_char, padding);
	if (arg_int >= 0 && flags->space == 1 && flags->zero == 1)
		pad_char[0] = ' ';
	if (arg_int >= 0 && flags->plus == 1 && flags->zero == 1)
		pad_char[0] = '+';
	return (pad_char);
}


/*
para el unsigned int:
	if (str2_i == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), 1);
*/
