/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 13:55:05 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/03 19:42:33 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		flag_reader(char *str2, int j, va_list args, t_modifiers *flags)
{
	char *width;

	if (ft_strchr("-", str2[j]))
		flags->minus = 1;
	if (ft_strchr("0", str2[j]))
		flags->zero = 1;
	if (ft_strchr(".", str2[j]))
		flags->is_precision = 1;
	if (ft_strchr("*", str2[j]))
		flags->star = 1;
	if (ft_strchr("#", str2[j]))
		flags->hash = 1;
	if (ft_strchr(" ", str2[j]))
		flags->space = 1;
	if (ft_strchr("+", str2[j]))
		flags->plus = 1;
	if (ft_strchr("0123456789", str2[j])) // y el 0?
		flags->is_width = 1;
	return (0);
}

void	flags_initialiser(t_modifiers *flags)
{
	flags->i = 0;
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

void	flag_sum(t_modifiers *flags)
{
	int		sum;

	sum = flags->minus + flags->is_precision + flags->star + flags->hash +
			flags->space + flags->plus + flags->is_width;
}
