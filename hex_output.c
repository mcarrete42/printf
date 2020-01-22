/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 23:01:24 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/22 19:26:25 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		hex_output(char str2_i, int i, va_list args, t_modifiers *flags)
{
	unsigned long int arg_hex;
	char *hex_str;
	int j;

	flags->conversion = str2_i;
	if (str2_i == 'x' || str2_i == 'X')
		arg_hex = va_arg(args, unsigned int);
	else if (str2_i == 'p')
		arg_hex = va_arg(args, unsigned long int);
	//printf("my arg_hex es: %d", arg_hex);
	if (arg_hex != 0 && str2_i == 'x')
		hex_str = ft_itoa_hex(arg_hex);
	else if (arg_hex != 0 && str2_i == 'X')
		hex_str = ft_itoa_hex_upper(arg_hex);
	else if (arg_hex == 0 && str2_i == 'X' || (arg_hex == 0 && str2_i == 'x'))
		hex_str = ft_strdup("0");
	else if (arg_hex != 0 && str2_i == 'p')
	{
		hex_str = ft_ltoa_hex(arg_hex);
		hex_str = ft_strjoin("0x", hex_str);
	}
	else if (arg_hex == 0 && str2_i == 'p')
		hex_str = ft_strdup("0x0");
	if (flags->is_precision == 1)
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
