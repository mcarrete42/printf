/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 17:23:29 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/19 15:54:56 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		type_reader(char *str, int i, va_list args, t_modifiers *flags)
{
	char *str2;

	str2 = (char*)str;
	while (str2[i] !='\0')
	{
		if (str2[i] != '%' && str2[i])
			ft_putchar_fd(str2[i], 1);
		else if (str2[i] == '%')
		{
			flags_initialiser(flags);
			if (!ft_strchr(CONVANDFLAGS, str[i + 1]))
				break;
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

	char_reader(str2_i, args);
	flags_initialiser(flags);
	return (0);
}

int		char_reader(char str2_i, va_list args)
{
	char				*str3;
	unsigned long		addr;
	char *str;

	/* if (str2_i == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	 if (str2_i == 's')
	{
		str3 = va_arg(args, char *);
		ft_putstr_fd(str3, 1);
		return (1);
	}
	if (str2_i == 'p')
	{
		addr = va_arg(args, unsigned long int);
		write(1, "0x", 2);
		str = ft_ltoa_hex(addr);
		ft_putstr_fd(str, 1);
		free(str);
		return (1);
	}
	else if (str2_i == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	} */
	return(0);
}
