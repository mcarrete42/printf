/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 13:55:05 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/19 18:33:00 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		flag_parser(char *str2, int i, va_list args, t_modifiers *flags)
{
	flags->i = i;
	flag_reader(str2, flags);
	width_definer(str2, args, flags);
	precision_definer(str2, args, flags);
	return (0);
}

void		flag_reader(char *str2, t_modifiers *flags)
{
	while (ft_strchr("0#-+ ", str2[flags->i]))
	{
		if (str2[flags->i] == '0' &&
			!(str2[flags->i - 1] > '0' &&  str2[flags->i - 1] < '9'))
			flags->zero = 1;
		if (str2[flags->i] == '#')
			flags->hash = 1;
		if (str2[flags->i] == '-')
			flags->minus = 1;
		if (str2[flags->i] == '+')
			flags->plus = 1;
		if (str2[flags->i] == ' ')
			flags->space = 1;
		flags->i++;
	}
	if (flags->space == 1)
		flags->plus = 0;
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
}

void	precision_definer(char *str2, va_list args, t_modifiers *flags)
{
	int precision;
	int i;

	i = flags->i;
	if (str2[i] == '.')
	{
		flags->is_precision = 1;
		flags->zero = 0;
		i++;
		if (str2[i] >= '0' && str2[i] <= '9')
		{
			flags->precision = ft_atoi(&str2[i]);
			while (str2[i] >= '0' && str2[i] <= '9')
				i++;
		}
		else if (str2[i] == '*')
		{
			precision = va_arg(args, int);
			if (precision >= 0)
				flags->precision = precision;
			else if (precision < 0)
				flags->precision = 0;
			else if (precision == 0)
				flags->precision = 1;
			while (str2[i] == '*')
				i++;
		}
	}
	flags->i = i;
}

void	width_definer(char *str2, va_list args, t_modifiers *flags)
{
	if (flags->width == 0 && str2[flags->i] == '*' && str2[flags->i - 1] != '.')
	{
		flags->width = va_arg(args, int);
		if (flags->width < 0)
			flags->minus = 1;
		while (str2[flags->i] == '*')
			flags->i++;		}
	else if (str2[flags->i] > '0' && str2[flags->i] <= '9' && str2[flags->i - 1] != '.')
	{
		flags->width = atoi(&str2[flags->i]);
		flags->i++;
	}
	else if (str2[flags->i] != '.')
		flags->i++;
}
