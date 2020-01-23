/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 13:55:05 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/23 07:40:03 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		flag_parser(char *str2, int i, va_list args, t_modifiers *flags)
{
	//printf("hola\n");

	flags->i = i;
	flag_reader(str2, flags);
	width_definer(str2, args, flags);
	precision_definer(str2, args, flags);
	return (0);
}

void	flag_reader(char *str2, t_modifiers *flags)
{
	while (ft_strchr("0#-+ ", str2[flags->i]))
	{
		if (str2[flags->i] == '0' &&
			!(str2[flags->i - 1] > '0' && str2[flags->i - 1] < '9'
			|| str2[flags->i - 1] == '.'))
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

void	precision_definer(char *str2, va_list args, t_modifiers *flags)
{
	int precision;
	int i;
//	printf("idfdfd\n");

	i = flags->i;
	//printf("%d\n", i);
	if (str2[i] == '.' && flags->is_precision == 0)
	{
		flags->is_precision = 1;
		flags->zero = 0;
		i++;
		//	printf("%s\n", str2 + i);
		if (str2[i] >= '0' && str2[i] <= '9')
		{
			flags->precision = ft_atoi(&str2[i]);
			while (str2[i] >= '0' && str2[i] <= '9')
				i++;
		}
		else if (str2[i] == '*')
		{
			star_precision(precision, args, flags);
			while (str2[i] == '*')
				i++;
		}
	}
	//	printf("2-%d\n", i);
	flags->i = i;
}

void	star_precision(int precision, va_list args, t_modifiers *flags)
{
	precision = va_arg(args, int);
//	printf("int pre %d\n", precision);
	if (precision >= 0)
		flags->precision = precision;
	else if (precision < 0)
		flags->is_precision = 0;
	else if (precision == 0)
		flags->precision = 1;
}

void	width_definer(char *str2, va_list args, t_modifiers *flags)
{
	//printf("int wi %d\n", flags->width);

	if (flags->width == 0 && str2[flags->i] == '*' && str2[flags->i - 1] != '.')
	{
		flags->width = va_arg(args, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->zero = 0;
			flags->width = -flags->width;
		}
		while (str2[flags->i] == '*')
			flags->i++;
	}
	else if (str2[flags->i] > '0' && str2[flags->i] <= '9' &&
		str2[flags->i - 1] != '.' && str2[flags->i - 2] != '.' &&
		!(str2[flags->i - 1] > '0' && str2[flags->i - 1] <= '9'))
	{
		flags->width = ft_atoi(&str2[flags->i]);
		flags->i++;
	}
	else if (str2[flags->i] != '.')
		flags->i++;
}
