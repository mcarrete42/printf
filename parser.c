/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 17:23:29 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/22 19:41:41 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		type_reader(char *str2, int i, va_list args, t_modifiers *flags)
{
	flags->ret_val = 0;
	while (str2[i] != '\0' && flags->error != 1)
	{
		if (str2[i] != '%' && str2[i])
			flags->ret_val += write(1, &str2[i], 1);
		else if (str2[i] == '%')
		{
			flags_initialiser(flags);
			if (!ft_strchr(CONVANDFLAGS, str2[i + 1]))
				break ;
			while (ft_strchr(CONVANDFLAGS, str2[i + 1]))
			{
				i = i + 1;
				if (ft_strchr(CONVERSIONS, str2[i]))
				{
					conversions(str2[i], i, args, flags);
					break ;
				}
				else if (ft_strchr(FLAGS, str2[i]))
					flag_parser(str2, i, args, flags);
			}
		}
		check_error(flags);
		i++;
	}
}

int		conversions(char str2_i, int i, va_list args, t_modifiers *flags)
{
	flags->i = i;
	if (str2_i == 'd' || str2_i == 'i' || str2_i == 'u')
		int_output(str2_i, i, args, flags);
	else if (str2_i == 'x' || str2_i == 'X' || str2_i == 'p')
		hex_output(str2_i, i, args, flags);
	else if (str2_i == 'f')
		float_output(str2_i, i, args, flags);
	else if (str2_i == 'c')
		char_output(str2_i, i, args, flags);
	else if (str2_i == '%')
		percent_output(str2_i, i, args, flags);
	else if (str2_i == 's')
		string_output(str2_i, i, args, flags);
	flags_initialiser(flags);
	return (0);
}

void	flags_initialiser(t_modifiers *flags)
{
	flags->minus = 0;
	flags->conversion = 0;
	flags->zero = 0;
	flags->precision = 0;
	flags->star = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->width = 0;
	flags->is_precision = 0;
	flags->float_dec = 0;
	flags->float_non_dec = 0;
	flags->error = 0;
	flags->is_negative = 0;
}

void	check_error(t_modifiers *flags)
{
	if (flags->ret_val <= 0)
	{
		write(1, "", 0);
		flags->error = 1;
	}
	else
	{
		flags->error = 0;
	}
}
