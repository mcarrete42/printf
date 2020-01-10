/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:24:59 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/10 19:02:11 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		int_output(char str2_i, int i, va_list args, t_modifiers *flags)
{
	char *str;

	if (flags->is_width == 1)
	{
		size_t width;
		width = (size_t)flags->width;
	}

	ft_putnbr_fd(va_arg(args, int), 1);
	return (0);
}

/*
para el unsigned int:
	if (str2_i == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), 1);
*/
