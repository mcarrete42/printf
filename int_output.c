/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:24:59 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/23 17:50:27 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		int_input(char str2_i, int i, va_list args, t_modifiers *flags)
{
	char	*str_arg;
	char	*str_int;

	flags->conversion = str2_i;
	if (str2_i == 'd' || str2_i == 'i')
		str_int = ft_itoa(va_arg(args, int));
	else if (str2_i == 'u')
		str_int = ft_ltoa(va_arg(args, unsigned int));
	str_arg = str_int;
	if (str_int[0] == '-')
		flags->is_negative = 1;
	if (flags->is_precision == 0 && flags->precision != 0)
		flags->precision = 0;
	int_out(str_int, str_arg, args, flags);
	return (0);
}

int		int_out(char *str_int, char *str_arg, va_list args, t_modifiers *flags)
{
	int		arg_int;

	if ((flags->is_negative == 1 && flags->precision > ft_strlen(str_int)) ||
	(flags->is_negative == 1 && flags->width > ft_strlen(str_arg) &&
	flags->zero == 1))
		str_int = ft_substr(str_int, 1, ft_strlen(str_int) - 1);
	if (str_int != str_arg)
	{
		if (flags->is_precision == 1)
			str_int = is_precision(str_int, args, flags);
		if (flags->width > ft_strlen(str_int))
			str_int = is_width(arg_int, str_int, args, flags);
		str_int = manage_negatives(str_int, str_arg, flags);
	}
	else
	{
		if (flags->is_precision == 1)
			str_int = is_precision(str_int, args, flags);
		if (flags->width > ft_strlen(str_int))
			str_int = is_width(arg_int, str_int, args, flags);
	}
	ft_putstr_fd(str_int, 1);
	flags->ret_val = flags->ret_val + ft_strlen(str_int);
	free(str_int);
	return (0);
}

char	*is_precision(char *str_int, va_list args, t_modifiers *flags)
{
	char	*pad_zero;
	int		zero_num;

	if (flags->precision != 0 && flags->precision <= ft_strlen(str_int))
		return (str_int);
	if (flags->precision == 0)
		str_int = "";
	zero_num = flags->is_negative == 0 ? flags->precision - ft_strlen(str_int)
		: (flags->precision - ft_strlen(str_int) + 1);
	if (flags->width > flags->precision && flags->is_negative == 1)
		zero_num = flags->precision - ft_strlen(str_int);
	if (!(pad_zero = malloc(sizeof(char) * zero_num)))
		return (NULL);
	ft_bzeroes(pad_zero, zero_num);
	str_int = ft_strjoin(pad_zero, str_int);
	free(pad_zero);
	return (str_int);
}

char	*is_width(int arg_int, char *str_int, va_list args, t_modifiers *flags)
{
	int		padding;
	char	*pad_char;
	char	*str_join;

	padding = flags->width - ft_strlen(str_int);
	if (flags->conversion == 'd' || flags->conversion == 'i'
		|| flags->conversion == 'f')
	{
		if ((flags->plus == 1 && flags->zero == 0) ||
		(flags->space == 1 && flags->zero == 0))
		{
			padding = padding - 1;
			str_int = plus_space(arg_int, str_int, flags);
		}
	}
	if (flags->is_negative == 1 && flags->width > 9 &&
		flags->width > flags->precision && flags->minus == 1)
		padding = padding - 1;
	if (!(pad_char = malloc(sizeof(char) * padding)))
		return (0);
	pad_char = zero_load(pad_char, padding, arg_int, flags);
	str_join = flags->minus == 0 ? ft_strjoin(pad_char, str_int)
	: ft_strjoin(str_int, pad_char);
	free(pad_char);
	return (str_join);
}

char	*manage_negatives(char *str_int, char *str_arg, t_modifiers *flags)
{
	if ((flags->is_negative == 1 && !(flags->width > flags->precision)
	&& flags->precision > ft_strlen(str_arg)) ||
	(flags->is_negative && flags->width > flags->precision && flags->zero == 1))
		str_int[0] = '-';
	if (flags->is_negative == 1 && flags->is_precision == 1 &&
	flags->width > flags->precision &&
	flags->minus == 0 && flags->zero == 0)
		str_int[(flags->width - flags->precision) - 1] = '-';
	if (flags->is_negative == 1 && flags->width > flags->precision
	&& flags->minus == 1 && str_int[0] != '-')
		str_int = ft_strjoin("-", str_int);
	return (str_int);
}
