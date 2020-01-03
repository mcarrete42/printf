/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 13:55:05 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/02 19:34:51 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		flag_reader(char *str2, int j, va_list args, t_modifiers *flags)
{
	char *width;
	flags_initialiser(flags);
	if (ft_strchr("-", str2[j]))
	{
		flags->minus = 1;
		printf ("\nEste es mi minus%d\n",1);
	}
	if (ft_strchr("0", str2[j]))
		flags->zero = 1;
	if (ft_strchr(".", str2[j]))
		flags->precision = str2[j + 1] + '0';
	if (ft_strchr("*", str2[j]))
		flags->star = 1;
	if (ft_strchr("#", str2[j]))
		flags->hash = 1;
	if (ft_strchr(" ", str2[j]))
		flags->space = 1;
	if (ft_strchr("+", str2[j]))
		flags->plus = 1;
	if (ft_strchr("123456789", str2[j])) // que pasa si hay un 0 aqui? se lia con el modifier 0?
	{
		width = ft_strchr("123456789", str2[j]);
		flags->width = width[0] + '0';
	}
	return (0);
}

void	flags_initialiser(t_modifiers *flags)
{
	flags->minus = 0;
	flags->precision = 0;
	flags->star = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->width = 0;
}
