/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 13:55:05 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/08 19:27:45 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		flag_parser(char *str2, int i, va_list args, t_modifiers *flags)
{
	flag_reader(str2, i, flags);
	precision_definer(str2, i, args, flags);
	//width_definer(str2, i, flags);
	return (0);
}

int		flag_reader(char *str2, int i, t_modifiers *flags)
{
	while (ft_strchr("0#-+ ", str2[flags->i]))
	{
		if (str2[i] == '0')
			flags->zero = 1;
		if (str2[i] == '#')
			flags->hash = 1;
		if (str2[i] == '-')
			flags->minus = 1;
		if (str2[i] == '+')
			flags->plus = 1;
		if (str2[i] == ' ')
			flags->space = 1;
		flags->i++;
	}
	return (0);
}

void	flags_initialiser(t_modifiers *flags)
{
	flags->minus = 0;
	flags->precision = 0;
	flags->is_precision = 0;
	flags->star = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->width = 0;
	flags->is_width = 0;
}

void	precision_definer(char *str2, int i, va_list args, t_modifiers *flags)
{
	int precision;

	i = flags->i;
	if (str2[i] == '.')
	{
		flags->is_precision = 1;
		if (str2[i + 1] >= '0' && str2[i + 1] <= '9')
		{
			flags->precision = ft_atoi(&str2[i + 1]);
			i++;
		}
		else if (str2[i + 1] == '*')
		{
			precision = va_arg(args, int);
			if (precision >= 0)
				flags->precision = precision;
			else if (precision < 0)
				flags->precision = 0;
			i++;
		}
	}
	flags->i = i;
}

void	width_definer(char *str2, int i, t_modifiers *flags)
{
	i = flags->i;
	if (str2[i] > '0' && str2[i] <= '9')
	{
		flags->is_width = 1;
		flags->width = atoi(&str2[i]);
		i++;
	}
}
