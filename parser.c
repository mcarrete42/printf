/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 17:23:29 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/19 21:55:43 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		type_reader(char *str, int i, va_list args, t_modifiers *flags)
{
	char *str2;

	flags->ret_val = 0;
	str2 = (char*)str;
	while (str2[i] !='\0')
	{
		if (str2[i] != '%' && str2[i])
		{
			ft_putchar_fd(str2[i], 1);
			flags->ret_val++;
		}
		else if (str2[i] == '%')
		{
			flags_initialiser(flags);
			if (!ft_strchr(CONVANDFLAGS, str[i + 1]))
				break;
			if (ft_strlen(str2) == 1 || !(ft_strchr(CONVANDFLAGS, str2[i + 1])))
				ft_putstr_fd("", 1);
			while (ft_strchr(CONVANDFLAGS, str2[i + 1]))
			{
				i = i + 1;
				if (ft_strchr(CONVERSIONS, str2[i]))
				{
					conversions(str2[i], i, args, flags);
					break;
				}
				else if (ft_strchr(FLAGS, str2[i]))
					flag_parser(str2, i, args, flags);
			}
		}
		i++;
	}
	return (0);
}

int	conversions(char str2_i, int i, va_list args, t_modifiers *flags)
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
