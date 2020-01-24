/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 23:01:24 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/24 19:18:46 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		hex_output(char str2_i, int i, va_list args, t_modifiers *flags)
{
	unsigned long int	arg_hex;
	char				*hex_str;

	flags->conversion = str2_i;
	if (str2_i == 'x' || str2_i == 'X')
		arg_hex = va_arg(args, unsigned int);
	if (arg_hex != 0 && str2_i == 'x')
		hex_str = ft_itoa_hex(arg_hex);
	else if (arg_hex != 0 && str2_i == 'X')
		hex_str = ft_itoa_hex_upper(arg_hex);
	else if ((arg_hex == 0 && str2_i == 'X') || (arg_hex == 0 && str2_i == 'x'))
		hex_str = ft_strdup("0");
	if ((flags->is_precision == 1 && str2_i == 'x') ||
	(flags->is_precision == 1 && str2_i == 'X'))
		hex_str = is_precision(hex_str, args, flags);
	if (flags->width > ft_strlen(hex_str))
		hex_str = is_width(arg_hex, hex_str, args, flags);
	if (flags->conversion == 'x' && flags->hash == 1 && arg_hex != 0)
		hex_str = ft_strjoin("0x", hex_str);
	else if (flags->conversion == 'X' && flags->hash == 1 && arg_hex != 0)
		hex_str = ft_strjoin("0X", hex_str);
	ft_putstr_fd(hex_str, 1);
	flags->ret_val = flags->ret_val + ft_strlen(hex_str);
	free(hex_str);
	return (0);
}

int		pointer_output(char str2_i, int i, va_list args, t_modifiers *flags)
{
	unsigned long int	arg_ptr;
	char				*ptr_str;

	flags->conversion = str2_i;
	arg_ptr = va_arg(args, unsigned long int);
	if (arg_ptr != 0)
	{
		ptr_str = (arg_ptr != 0) ? ft_ltoa_hex(arg_ptr) : ft_strdup("");
		ptr_str = ft_strjoin("0x", ptr_str);
	}
	else if (arg_ptr == 0 && str2_i == 'p' && flags->is_precision == 0)
		ptr_str = ft_strdup("0x0");
	else if (flags->is_precision == 1 && str2_i == 'p')
	{
		if (arg_ptr == 0 && flags->is_precision == 1 && flags->precision == 0)
			ptr_str = ft_strdup("0x");
		else if (flags->is_precision == 1 && flags->precision == 0)
			flags->is_precision = 0;
	}
	if (flags->width > ft_strlen(ptr_str))
		ptr_str = is_width(arg_ptr, ptr_str, args, flags);
	ft_putstr_fd(ptr_str, 1);
	flags->ret_val = flags->ret_val + ft_strlen(ptr_str);
	free(ptr_str);
	return (0);
}
